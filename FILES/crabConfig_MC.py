from http.client import HTTPException
from multiprocessing import Process
from pathlib import Path
from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException
from CRABClient.UserUtilities import config as crab_config

PTHAT_BINS = (5, 10, 15, 30, 50)
XFINDER_CHANNEL_SWITCHES = (0, 0, 0, 0, 0, 0, 1)

SITE_WHITELIST = [
    "T2_CH_CERN", "T2_BE_IIHE", "T2_DE_DESY", "T2_DE_RWTH", "T2_ES_CIEMAT", "T2_IT_Bari", "T2_IT_Legnaro", "T2_IT_Rome",
    "T2_UK_London_Brunel", "T2_US_Caltech", "T2_US_MIT", "T2_US_Nebraska", "T2_US_Purdue", "T2_US_UCSD", "T2_US_Wisconsin",
]

CAMPAIGNS = {
    "pbpb23": {
        "pset": "forest_miniAOD_run3_MC_wBfinder_2023.py",
        "work_area": "crab_projects_X/MC_pbpb23",
        "out_lfn": "/store/user/hmarques/RUN3_MCs/MC_PbPb23_X3872/",
        "units_per_job": 2000,
        "processing": "HINPbPbSpring23MiniAOD-132X_mcRun3_2023_realistic_HI_v9-v2",
        "request_prefix": "MC_PbPb",
        "name_suffix": "pbpb23",
    },
    "ppref": {
        "pset": "Bfinder_ppRef24_MC.py",
        "work_area": "crab_projects_X/MC_ppRef",
        "out_lfn": "/store/user/hmarques/RUN3_MCs/MC_ppRef_X3872/",
        "units_per_job": 50000,
        "processing": "RunIIIpp5p36Winter24MiniAOD-141X_mcRun3_2024_realistic_ppRef5TeV_v7-v2",
        "request_prefix": "MC_ppRef",
        "name_suffix": "",
    },
}

# Only complete official global-DBS sample families belong in this table.
OFFICIAL_SAMPLE_FAMILIES = {
    ("pbpb23", "prompt", "x3872"): {
        "primary": "PromptX3872ToJPsiRho",
        "generator_suffix": "",
        "decay_name": "X3872_to_Jpsi_Rho",
    },
    ("pbpb23", "nonprompt", "x3872"): {
        "primary": "NonpromptX3872ToJPsiRho",
        "generator_suffix": "",
        "decay_name": "X3872_to_Jpsi_Rho",
    },
    ("pbpb23", "prompt", "x3872_pipi"): {
        "primary": "PromptX3872ToJPsiPiPi",
        "generator_suffix": "-evtgen",
        "decay_name": "X3872_to_Jpsi_pipi",
    },
    ("pbpb23", "prompt", "psi2s"): {
        "primary": "PromptPsi2SToJPsiPiPi",
        "generator_suffix": "-evtgen",
        "decay_name": "PSI2S_to_Jpsi_pipi",
    },
    ("pbpb23", "nonprompt", "psi2s"): {
        "primary": "NonpromptPsi2SToJPsiPiPi",
        "generator_suffix": "-evtgen",
        "decay_name": "PSI2S_to_Jpsi_pipi",
    },
    ("ppref", "prompt", "psi2s"): {
        "primary": "PromptPsi2SToJPsiPiPi",
        "generator_suffix": "-evtgen",
        "decay_name": "PSI2S_to_Jpsi_pipi",
    },
    ("ppref", "nonprompt", "psi2s"): {
        "primary": "NonpromptPsi2SToJPsiPiPi",
        "generator_suffix": "-evtgen",
        "decay_name": "PSI2S_to_Jpsi_pipi",
    },
    ("ppref", "prompt", "x3872_pipi"): {
        "primary": "PromptX3872ToJPsiPiPi",
        "generator_suffix": "-evtgen",
        "decay_name": "X3872_to_Jpsi_pipi",
        "processing": "RunIIIpp5p36Winter24MiniAOD-141X_mcRun3_2024_realistic_ppRef5TeV_v7-v1",
    },
}


def build_dataset(campaign, sample, pthat):
    primary_dataset = (
        f"{sample['primary']}_pThat-{pthat}_TuneCP5_5p36TeV_pythia8"
        f"{sample['generator_suffix']}"
    )
    processing = sample.get("processing", campaign["processing"])
    return f"/{primary_dataset}/{processing}/MINIAODSIM"


def set_x_bfinder_channel(pset_name):
    replacement = (
        "process.Bfinder.Bchannel = cms.vint32("
        + ", ".join(str(value) for value in XFINDER_CHANNEL_SWITCHES)
        + ")\n"
    )

    source_path = Path(pset_name)
    if not source_path.is_absolute():
        source_path = Path(__file__).resolve().parent / source_path
    source_path = source_path.resolve()

    output_lines = []
    replacement_count = 0
    with source_path.open(encoding="utf-8") as source:
        for line in source:
            stripped_line = line.lstrip()
            if stripped_line.startswith("process.Bfinder.Bchannel"):
                indentation = line[: len(line) - len(stripped_line)]
                output_lines.append(indentation + replacement)
                replacement_count += 1
            else:
                output_lines.append(line)

    if replacement_count != 1:
        raise RuntimeError(
            f"Expected one Bchannel assignment in '{source_path}', "
            f"found {replacement_count}"
        )

    source_path.write_text("".join(output_lines), encoding="utf-8")
    return source_path


def build_task_config(sample_key, pthat):
    campaign_name, production, _ = sample_key
    campaign = CAMPAIGNS[campaign_name]
    sample = OFFICIAL_SAMPLE_FAMILIES[sample_key]

    task_config = crab_config()

    task_config.General.transferOutputs = True
    task_config.General.workArea = campaign["work_area"]

    task_config.JobType.pluginName = "Analysis"
    task_config.JobType.psetName = campaign["pset"]
    task_config.JobType.maxMemoryMB = 2500
    task_config.JobType.maxJobRuntimeMin = 1000
    task_config.JobType.numCores = 1
    task_config.JobType.pyCfgParams = ["noprint"]
    task_config.JobType.outputFiles = ["HiForestMINIAOD_MC.root"]

    task_config.Data.inputDBS = "global"
    task_config.Data.inputDataset = build_dataset(campaign, sample, pthat)
    task_config.Data.splitting = "EventAwareLumiBased"
    task_config.Data.unitsPerJob = campaign["units_per_job"]
    task_config.Data.totalUnits = -1
    task_config.Data.ignoreLocality = True
    task_config.Data.publication = False
    task_config.Data.outLFNDirBase = campaign["out_lfn"]

    base_name = (
        f"{production}_{sample['decay_name']}_phat{pthat}_Bfinder"
        + (f"_{campaign['name_suffix']}" if campaign["name_suffix"] else "")
    )
    task_config.General.requestName = f"{campaign['request_prefix']}_{base_name}"
    task_config.Data.outputDatasetTag = base_name

    task_config.Site.whitelist = SITE_WHITELIST
    task_config.Site.storageSite = "T3_CH_CERNBOX"

    return task_config


def run_crab_submit(task_config):
    try:
        crabCommand("submit", config=task_config, dryrun=False)
    except HTTPException as error:
        print(f"HTTP error while submitting: {error.headers}")
    except ClientException as error:
        print(f"CRAB error while submitting: {error}")


def submit(task_config):
    pset_path = set_x_bfinder_channel(task_config.JobType.psetName)
    task_config.JobType.psetName = str(pset_path)

    print(f"Submitting {task_config.General.requestName}")
    print(f"  input: {task_config.Data.inputDataset}")
    print(f"  Bchannel: {XFINDER_CHANNEL_SWITCHES}")

    submission = Process(target=run_crab_submit, args=(task_config,))
    submission.start()
    submission.join()
    if submission.exitcode:
        print(
            f"Submission process failed with exit code {submission.exitcode}: "
            f"{task_config.General.requestName}"
        )


def submit_enabled_samples(submission_flags):
    for sample_key, enabled in submission_flags.items():
        if not enabled:
            continue

        for pthat in PTHAT_BINS:
            submit(build_task_config(sample_key, pthat))


######################################################################################################################################################
###################################          SUBMISSION FLAGS          ###################################
######################################################################################################################################################

# Official ppRef samples.
SUBMIT_PPREF_MC_PROMPT_X_PIPI = True
SUBMIT_PPREF_MC_PROMPT_PSI2S = True
SUBMIT_PPREF_MC_NONPROMPT_PSI2S = True

# Official PbPb23 samples.
SUBMIT_PBPB23_MC_PROMPT_X = False
SUBMIT_PBPB23_MC_NONPROMPT_X = False
SUBMIT_PBPB23_MC_PROMPT_X_PIPI = False
SUBMIT_PBPB23_MC_PROMPT_PSI2S = False
SUBMIT_PBPB23_MC_NONPROMPT_PSI2S = False


SUBMISSION_FLAGS = {
    ("ppref", "prompt", "x3872_pipi"): SUBMIT_PPREF_MC_PROMPT_X_PIPI,
    ("ppref", "prompt", "psi2s"): SUBMIT_PPREF_MC_PROMPT_PSI2S,
    ("ppref", "nonprompt", "psi2s"): SUBMIT_PPREF_MC_NONPROMPT_PSI2S,
    ("pbpb23", "prompt", "x3872"): SUBMIT_PBPB23_MC_PROMPT_X,
    ("pbpb23", "nonprompt", "x3872"): SUBMIT_PBPB23_MC_NONPROMPT_X,
    ("pbpb23", "prompt", "x3872_pipi"): SUBMIT_PBPB23_MC_PROMPT_X_PIPI,
    ("pbpb23", "prompt", "psi2s"): SUBMIT_PBPB23_MC_PROMPT_PSI2S,
    ("pbpb23", "nonprompt", "psi2s"): SUBMIT_PBPB23_MC_NONPROMPT_PSI2S,
}


if __name__ == "__main__":
    submit_enabled_samples(SUBMISSION_FLAGS)
