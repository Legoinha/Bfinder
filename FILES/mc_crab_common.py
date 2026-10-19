"""Shared CRAB machinery for running the forest + Bfinder over MC MiniAOD (official or private samples).

Used by crabConfig_MC.py (X(3872)/psi(2S) -> J/psi pi pi, ntmix) and crabConfig_B_MC.py (B mesons).
Each of those scripts only defines its samples and a mode per sample:
    "official"  run over the official (global DBS) MiniAODSIM
    "private"   run over our private MiniAOD (phys03)
    "no_run"    skip
The same file lives in both CMSSW areas: the 2023/2024/ppRef campaigns are submitted from CMSSW_14_1_X,
PbPb 2025 from CMSSW_15_1_X. Tasks of the other release are listed as skipped, so one mode table serves both.
"""
import argparse
import os
import subprocess
from http.client import HTTPException
from multiprocessing import Process
from pathlib import Path

FILES_DIR = Path(__file__).resolve().parent
MODES = ("official", "private", "no_run")
PTHAT_BINS = (5, 10, 15, 30, 50)

SITE_WHITELIST = [
    "T2_CH_CERN", "T2_DE_DESY", "T2_DE_RWTH",  # no T2_BE_IIHE / T2_ES_CIEMAT (Oct 2026 failures) "T2_IT_Bari", "T2_IT_Legnaro", "T2_IT_Rome",
    "T2_UK_London_Brunel", "T2_US_Caltech", "T2_US_MIT", "T2_US_Nebraska", "T2_US_Purdue", "T2_US_UCSD", "T2_US_Wisconsin",
    "T2_US_Vanderbilt",  # private MiniAOD storage
]

CAMPAIGNS = {
    "pbpb23": {
        "cmssw": "CMSSW_14_1_",
        "pset": "forest_miniAOD_run3_MC_wBfinder_2023.py",
        "official_processing": "HINPbPbSpring23MiniAOD-132X_mcRun3_2023_realistic_HI_v9-v2",
        "work_dir": "MC_pbpb23",
        "out_dir": "MC_PbPb23",
        "units_per_job": 2000,
        "request_prefix": "MC_PbPb",
        "name_suffix": "pbpb23",
    },
    "pbpb24": {
        "cmssw": "CMSSW_14_1_",
        "pset": "forest_miniAOD_run3_MC_wBfinder_2024.py",
        # official PbPb 2024 B/onia requests (HIN-HINPbPbWinter24GSHIMix-00040..79, CMSSW_14_1_9_patch3) are only
        # defined in McM: the '*' is resolved in DAS once they are produced, until then the tasks are skipped
        "official_processing": "HINPbPbWinter24MiniAOD-*",
        "work_dir": "MC_pbpb24",
        "out_dir": "MC_PbPb24",
        "units_per_job": 2000,
        "request_prefix": "MC_PbPb",
        "name_suffix": "pbpb24",
    },
    "pbpb25": {
        "cmssw": "CMSSW_15_1_",
        "pset": "forest_miniAOD_run3_MC_wBfinder_2025.py",
        # 2025 MC centrality table is read from this sqlite file (not yet in a GT)
        "input_files": ["CentralityTable_HFtowers200_HydjetCello_v1510x0_official_MC2025.db"],
        "official_processing": None,  # no official PbPb 2025 signal MC
        "work_dir": "MC_pbpb25",
        "out_dir": "MC_PbPb25",
        "units_per_job": 2000,
        "request_prefix": "MC_PbPb",
        "name_suffix": "pbpb25",
    },
    "ppref24": {
        "cmssw": "CMSSW_14_1_",
        "pset": "Bfinder_ppRef24_MC.py",
        "official_processing": "RunIIIpp5p36Winter24MiniAOD-141X_mcRun3_2024_realistic_ppRef5TeV_v7-v2",
        "work_dir": "MC_ppRef",
        "out_dir": "MC_ppRef",
        "units_per_job": 50000,
        "request_prefix": "MC_ppRef",
        "name_suffix": "",
    },
}


def das_datasets(pattern, instance):
    query = f"dataset dataset={pattern}" + (f" instance={instance}" if instance != "global" else "")
    result = subprocess.run(["dasgoclient", "-query", query], capture_output=True, text=True)
    return [line for line in result.stdout.split() if line.startswith("/")]


def private_inputs(spec):
    """{pthat: dataset} from a private-sample spec: a '{pthat}' pattern (a '*' is resolved in DAS) or a dict."""
    if isinstance(spec, dict):
        return dict(spec)
    return {pthat: spec.format(pthat=pthat) for pthat in PTHAT_BINS}


def write_pset(campaign, bchannel, path):
    """Copy of the campaign pset with the requested Bfinder channels (the pset in git is not touched)."""
    replacement = "process.Bfinder.Bchannel = cms.vint32(" + ", ".join(str(v) for v in bchannel) + ")\n"
    lines, count = [], 0
    for line in (FILES_DIR / campaign["pset"]).read_text(encoding="utf-8").splitlines(keepends=True):
        if line.lstrip().startswith("process.Bfinder.Bchannel"):
            line = line[: len(line) - len(line.lstrip())] + replacement
            count += 1
        lines.append(line)
    if count != 1:
        raise RuntimeError(f"Expected one Bchannel assignment in {campaign['pset']}, found {count}")
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("".join(lines), encoding="utf-8")
    return path


def make_task(analysis, campaign_key, mode, pthat, base_name, dataset, bchannel):
    """One task description; base_name is the official-style name (the private one gets a PRIVATE tag)."""
    campaign = CAMPAIGNS[campaign_key]
    if campaign["name_suffix"]:
        base_name += "_" + campaign["name_suffix"]
    if mode == "private":
        base_name = "PRIVATE_" + base_name
    return {
        "analysis": analysis, "campaign": campaign_key, "mode": mode, "pthat": pthat, "dataset": dataset, "bchannel": bchannel,
        "request": f"{campaign['request_prefix']}_{base_name}", "tag": base_name,
    }


def crab_config(task, pset_path):
    from CRABClient.UserUtilities import config as new_config

    campaign = CAMPAIGNS[task["campaign"]]
    analysis = task["analysis"]
    c = new_config()
    c.General.requestName = task["request"]
    c.General.workArea = str(Path(os.environ["CMSSW_BASE"]) / "src" / analysis["work_area"] / campaign["work_dir"])
    c.General.transferOutputs = True

    c.JobType.pluginName = "Analysis"
    c.JobType.psetName = str(pset_path)
    c.JobType.inputFiles = [str(FILES_DIR / f) for f in campaign.get("input_files", [])]
    c.JobType.maxMemoryMB = 2500
    c.JobType.maxJobRuntimeMin = 1000
    c.JobType.numCores = 1
    c.JobType.pyCfgParams = ["noprint"]
    c.JobType.outputFiles = ["HiForestMINIAOD_MC.root"]

    c.Data.inputDBS = "phys03" if task["mode"] == "private" else "global"
    c.Data.inputDataset = task["dataset"]
    c.Data.splitting = "EventAwareLumiBased"
    c.Data.unitsPerJob = campaign["units_per_job"]
    c.Data.totalUnits = -1
    c.Data.ignoreLocality = True
    c.Data.publication = False
    # e.g. /store/user/hmarques/RUN3_MCs/MC_PbPb25_X3872_PRIVATE/ (= /eos/user/h/hmarques/RUN3_MCs/... on CERNBox)
    c.Data.outLFNDirBase = (f"/store/user/hmarques/RUN3_MCs/{campaign['out_dir']}_{analysis['out_label']}"
                            f"_{task['mode'].upper()}/")
    c.Data.outputDatasetTag = task["tag"]

    c.Site.whitelist = SITE_WHITELIST
    c.Site.storageSite = "T3_CH_CERNBOX"
    return c


def run_crab_submit(config):
    from CRABAPI.RawCommand import crabCommand
    from CRABClient.ClientExceptions import ClientException
    try:
        crabCommand("submit", config=config, dryrun=False)
    except HTTPException as error:
        print(f"HTTP error while submitting: {error.headers}")
    except ClientException as error:
        print(f"CRAB error while submitting: {error}")


def check_modes(modes):
    bad = {key: mode for key, mode in modes.items() if mode not in MODES}
    if bad:
        raise SystemExit(f"Unknown mode(s) {bad}; use one of {MODES}")


def main(analysis, tasks, problems):
    """List the tasks (default) or submit them (--submit). `problems` are configuration errors found while
    building the tasks (e.g. mode 'official' for a sample that has no official version)."""
    parser = argparse.ArgumentParser()
    parser.add_argument("--submit", action="store_true", help="submit (default: only list what would be submitted)")
    parser.add_argument("--pthat", type=int, nargs="+", help="restrict to these pThat bins")
    args = parser.parse_args()

    if problems:
        raise SystemExit("Fix the mode table first:\n  " + "\n  ".join(problems))
    if args.pthat:
        tasks = [t for t in tasks if t["pthat"] in args.pthat]

    release = os.environ.get("CMSSW_VERSION", "")
    ready, skipped = [], []
    for task in tasks:
        campaign = CAMPAIGNS[task["campaign"]]
        if not release.startswith(campaign["cmssw"]):
            skipped.append((task, f"needs {campaign['cmssw']}X (this is {release or 'no cmsenv'})"))
            continue
        instance = "prod/phys03" if task["mode"] == "private" else "global"
        if "*" in task["dataset"]:
            found = das_datasets(task["dataset"], instance)
            if len(found) != 1:
                skipped.append((task, f"{len(found)} DAS matches for {task['dataset']}"))
                continue
            task["dataset"] = found[0]
        elif not das_datasets(task["dataset"], instance):
            skipped.append((task, f"not in DAS: {task['dataset']}"))
            continue
        ready.append(task)

    for task in ready:
        print(f"{'SUBMIT' if args.submit else 'would submit'}  {task['request']}\n    {task['mode']:8s} {task['dataset']}")
    for task, reason in skipped:
        print(f"skipped  {task['request']}: {reason}")
    print(f"{len(ready)} task(s) ready, {len(skipped)} skipped" + ("" if args.submit else "  (list only; use --submit)"))
    if not args.submit:
        return

    for task in ready:
        campaign = CAMPAIGNS[task["campaign"]]
        work_area = Path(os.environ["CMSSW_BASE"]) / "src" / analysis["work_area"] / campaign["work_dir"]
        if (work_area / f"crab_{task['request']}").exists():
            print(f"[!] work area exists, skipping {task['request']}")
            continue
        pset = write_pset(campaign, task["bchannel"], work_area / "psets" / f"{task['request']}_cfg.py")
        # CRAB can load only one CMSSW config per python process: submit each task in its own process
        submission = Process(target=run_crab_submit, args=(crab_config(task, pset),))
        submission.start()
        submission.join()
        if submission.exitcode:
            print(f"Submission process failed with exit code {submission.exitcode}: {task['request']}")
