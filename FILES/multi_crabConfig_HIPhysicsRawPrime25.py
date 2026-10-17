from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException
from http.client import HTTPException
import argparse
import os

# PbPb 2025 data (HIRun2025A PromptReco MINIAOD), run from CMSSW_15_1_2 after cmsenv:
#   python3 multi_crabConfig_HIPhysicsRawPrime25.py            -> list what would be submitted
#   python3 multi_crabConfig_HIPhysicsRawPrime25.py --submit   -> submit
#   python3 multi_crabConfig_HIPhysicsRawPrime25.py --submit --only 0   -> submit only HIPhysicsRawPrime0 (test)
HERE = os.path.dirname(os.path.abspath(__file__))

from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.workArea = os.path.join(HERE, '..', '..', 'crab_projects_PbPb25_DATA')
config.General.transferOutputs = True
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = "Analysis"
config.JobType.psetName = os.path.join(HERE, "forest_miniAOD_run3_DATA_wBfinder_2025.py")
config.JobType.maxMemoryMB = 2500         # 2024 jobs: median 1941 MB, 19% above 2000 MB

config.JobType.numCores = 1 # must match the number of threads enabled in the pset config file!
config.JobType.allowUndistributedCMSSW = True
config.JobType.maxJobRuntimeMin = 1200 # max = 2750; 660 was too short on slow sites (2025: max 638 min, 13 jobs killed at T2_BE_IIHE)
config.JobType.pyCfgParams = ['noprint']
config.JobType.outputFiles = ['HiForestMINIAOD_PbPb2025.root']
# 2025 centrality table is not in any GT yet: ship the sqlite file (connect = sqlite_file:<name> in the pset)
config.JobType.inputFiles = [os.path.join(HERE, 'CentralityTable_HFtowers200_DataPbPb2025_periHYDJETshape_run3v1510x01_offline_Nominal.db')]

config.section_("Data")
config.Data.inputDBS = 'global'
config.Data.splitting = "FileBased"
config.Data.unitsPerJob = 9   # ~71k events/file in 2025, as in 2024 (~75k)
config.Data.publication = False
config.Data.runRange = '399465-400426'
config.Data.lumiMask = 'https://cms-service-dqmdc.web.cern.ch/CAF/certification/Collisions25HI/Cert_Collisions2025_HI_399465_400426_Muon.json'
config.Data.ignoreLocality = True      ## only when necessay (to speed up job processing)
config.Data.outLFNDirBase = '/store/user/hmarques/DATA_PbPb25'

config.section_("Site")
config.Site.storageSite = "T2_PT_NCG_Lisbon"
config.Site.whitelist = [
    'T2_CH_CERN','T2_BE_IIHE','T2_DE_DESY','T2_DE_RWTH','T2_ES_CIEMAT',
    'T2_IT_Bari','T2_IT_Rome','T2_UK_London_Brunel', 'T2_PT_NCG_Lisbon',
    'T2_US_Caltech','T2_US_Florida','T2_US_MIT','T2_US_Nebraska','T2_US_Purdue','T2_US_UCSD','T2_US_Wisconsin'
]


# Multi crab part
def get_datasets_from_file(filename):
    with open(filename, 'r') as f:
        datasets = [line.strip() for line in f if line.strip()]
    return datasets


# 60 HIPhysicsRawPrime PDs (0-59), ~5100 files each. The HIRun2025A-PbPbEW-PromptReco-v1 copies
# (same runs, ~0.4% of the events) are deliberately not in the list.
def submit_multiple_datasets(dataset_list, submit):
    for dataset in dataset_list:
        pd_index = dataset.split('/')[1].replace('HIPhysicsRawPrime', '')
        config.General.requestName = f'RawPrime{pd_index}_PbPb25'
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


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--submit', action='store_true', help='actually submit (default: only list)')
    parser.add_argument('--only', nargs='+', help='PD indices to submit, e.g. --only 0 1')
    args = parser.parse_args()

    for f in [config.JobType.psetName] + config.JobType.inputFiles:
        if not os.path.exists(f):
            raise SystemExit(f"missing {f}")

    datasets = get_datasets_from_file(os.path.join(HERE, "datasets_pbpb2025.txt"))
    if args.only:
        datasets = [d for d in datasets if d.split('/')[1].replace('HIPhysicsRawPrime', '') in args.only]
    submit_multiple_datasets(datasets, args.submit)
