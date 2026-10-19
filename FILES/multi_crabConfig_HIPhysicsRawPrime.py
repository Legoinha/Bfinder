from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException
from http.client import HTTPException
import argparse
import os
import subprocess

# PbPb 2023 data (HIRun2023A PromptReco-v2 MINIAOD), run from CMSSW_14_1_8 after cmsenv:
#   python3 multi_crabConfig_HIPhysicsRawPrime.py            -> list what would be submitted
#   python3 multi_crabConfig_HIPhysicsRawPrime.py --submit   -> submit
#   python3 multi_crabConfig_HIPhysicsRawPrime.py --submit --only 0   -> submit only the tasks of HIPhysicsRawPrime0 (test)
# Refuses to submit while old outputs are still at LIP (/store/user/hmarques/DATA_PbPb23), so old and new productions never mix.
HERE = os.path.dirname(os.path.abspath(__file__))
LIP = 'root://xroot01.ncg.ingrid.pt:1094'

from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.workArea = os.path.join(HERE, '..', '..', 'crab_projects_PbPb23_DATA')
config.General.transferOutputs = True
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = "Analysis"
config.JobType.psetName = os.path.join(HERE, "forest_miniAOD_run3_DATA_wBfinder_2023.py")
config.JobType.maxMemoryMB = 2500         # CRAB max for 1 core; old 2023 jobs peaked above 2000 MB
config.JobType.numCores = 1 # must match the number of threads enabled in the pset config file!
config.JobType.allowUndistributedCMSSW = True
config.JobType.maxJobRuntimeMin = 1200 # max = 2750; old 2023 jobs: ~2.5 h average, 6 h max
config.JobType.pyCfgParams = ['noprint']
config.JobType.outputFiles = ['HiForestMINIAOD.root']

config.section_("Data")
config.Data.inputDBS = 'global'
config.Data.splitting = "FileBased"
config.Data.unitsPerJob = 10   # ~140k events/file
config.Data.publication = False
config.Data.runRange = '374288-375823'
config.Data.lumiMask = 'https://cms-service-dqmdc.web.cern.ch/CAF/certification/Collisions23HI/Cert_Collisions2023HI_374288_375823_Muon.json'
config.Data.ignoreLocality = True      ## only when necessay (to speed up job processing)
config.Data.outLFNDirBase = '/store/user/hmarques/DATA_PbPb23'

config.section_("Site")
config.Site.storageSite = "T2_PT_NCG_Lisbon"
config.Site.whitelist = [
    'T2_CH_CERN','T2_BE_IIHE','T2_DE_DESY','T2_DE_RWTH','T2_ES_CIEMAT',
    'T2_IT_Bari','T2_IT_Rome','T2_UK_London_Brunel', 'T2_PT_NCG_Lisbon',
    'T2_US_Caltech','T2_US_Florida','T2_US_MIT','T2_US_Nebraska','T2_US_Purdue','T2_US_UCSD','T2_US_Wisconsin'
]


def old_outputs_at_lip():
    """Entries left in the output folder at LIP (empty list if it was cleaned or never existed)."""
    out = subprocess.run(['xrdfs', LIP, 'ls', config.Data.outLFNDirBase], capture_output=True, text=True)
    return out.stdout.split() if out.returncode == 0 else []


def submit_multiple_datasets(dataset_list, submit):
    for dataset in dataset_list:
        config.General.requestName = request_name(dataset)
        config.Data.inputDataset = dataset
        config.Data.outputDatasetTag = config.General.requestName

        work_area = os.path.join(config.General.workArea, f"crab_{config.General.requestName}")
        if os.path.exists(work_area):
            print(f"[!] Skipping {dataset}: working area already exists -> {work_area}")
            continue

        if not submit:
            print(f"[dry] would submit {config.General.requestName}: {dataset}")
            continue
        print("Submitting CRAB job for: " + dataset)
        try:
            crabCommand('submit', config = config, dryrun=False)
        except (HTTPException, ClientException) as e:
            print(f"[!] Submission failed for {dataset}: {e}")


# 32 HIPhysicsRawPrime PDs (0-31), 5.0 to 5.5k files each
DATASETS = [f"/HIPhysicsRawPrime{i}/HIRun2023A-PromptReco-v2/MINIAOD" for i in range(32)]


def request_name(dataset):
    return dataset.split('/')[1].replace('HIPhysics', '') + '_PbPb23'


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--submit', action='store_true', help='actually submit (default: only list)')
    parser.add_argument('--only', nargs='+', help='PD indices to submit, e.g. --only 0 1')
    args = parser.parse_args()

    for f in [config.JobType.psetName] + list(getattr(config.JobType, "inputFiles", None) or []):
        if not os.path.exists(f):
            raise SystemExit(f"missing {f}")
    leftovers = old_outputs_at_lip()
    if leftovers:
        msg = f"{len(leftovers)} entries still in {config.Data.outLFNDirBase} at LIP (old production): clean it first"
        if args.submit:
            raise SystemExit("[!] " + msg)
        print("[!] " + msg)

    datasets = DATASETS
    if args.only:
        datasets = [d for d in datasets if d.split('/')[1].replace('HIPhysicsRawPrime', '') in args.only]
    submit_multiple_datasets(datasets, args.submit)
