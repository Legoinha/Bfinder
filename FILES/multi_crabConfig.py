from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException
from http.client import HTTPException
import argparse
import os

# ppRef 2024 data (PPRefDoubleMuon0-3, Run2024J PromptReco MINIAOD), run from CMSSW_14_1_8 after cmsenv:
#   python3 multi_crabConfig.py            -> list what would be submitted
#   python3 multi_crabConfig.py --submit   -> submit
#   python3 multi_crabConfig.py --submit --only 0   -> submit only PPRefDoubleMuon0 (test)
HERE = os.path.dirname(os.path.abspath(__file__))

from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.workArea = os.path.join(HERE, '..', '..', 'crab_projects_ppRef_DATA')
config.General.transferOutputs = True
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = "Analysis"
config.JobType.psetName = os.path.join(HERE, "Bfinder_ppRef24_DATA.py")
config.JobType.maxMemoryMB = 2200
config.JobType.numCores = 1 # must match the number of threads enabled in the pset config file!
config.JobType.allowUndistributedCMSSW = True
config.JobType.maxJobRuntimeMin = 500 # max = 2750
config.JobType.pyCfgParams = ['noprint']
config.JobType.outputFiles = ['HiForestMINIAOD_ppRefData.root']

config.section_("Data")
config.Data.inputDBS = 'global'
config.Data.splitting = "EventAwareLumiBased"
config.Data.unitsPerJob = 500000
config.Data.allowNonValidInputDataset = True
config.Data.publication = False
config.Data.runRange = '387474-387721'
config.Data.lumiMask = 'https://cms-service-dqmdc.web.cern.ch/CAF/certification/Collisions24/Cert_Collisions2024_ppref_387474_387721_Muon.json'
config.Data.ignoreLocality = True      ## only when necessay (to speed up job processing)
config.Data.outLFNDirBase = '/store/user/hmarques/PPRef2024/'

config.section_("Site")
config.Site.storageSite = "T3_CH_CERNBOX"
# T2_BE_IIHE / T2_ES_CIEMAT left out: Oct 2026 job kills, bad job reports and input read errors (8028) there
config.Site.whitelist = [
    'T2_CH_CERN','T2_DE_DESY','T2_DE_RWTH',
    'T2_IT_Bari','T2_IT_Legnaro','T2_IT_Rome','T2_UK_London_Brunel', 'T2_PT_NCG_Lisbon',
    'T2_US_Caltech','T2_US_Florida','T2_US_MIT','T2_US_Nebraska','T2_US_Purdue','T2_US_UCSD','T2_US_Wisconsin'
]

# 4 PPRefDoubleMuon PDs, ~1.5k files each, average of 150k events/file
DATASETS = [f"/PPRefDoubleMuon{i}/Run2024J-PromptReco-v1/MINIAOD" for i in range(4)]


def request_name(dataset):
    return dataset.split('/')[1]


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


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--submit', action='store_true', help='actually submit (default: only list)')
    parser.add_argument('--only', nargs='+', help='PD indices to submit, e.g. --only 0 1')
    args = parser.parse_args()

    if not os.path.exists(config.JobType.psetName):
        raise SystemExit(f"missing {config.JobType.psetName}")

    datasets = DATASETS
    if args.only:
        datasets = [d for d in datasets if d.split('/')[1].replace('PPRefDoubleMuon', '') in args.only]
    submit_multiple_datasets(datasets, args.submit)
