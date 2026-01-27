from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException
from http.client import HTTPException
import os

# We want to put all the CRAB project directories from the tasks we submit here into one common directory.
# That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.workArea = 'crab_projects_X24'
config.General.transferOutputs = True
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = "Analysis"
config.JobType.psetName = "forest_miniAOD_run3_DATA_wBfinder_2024.py"
config.JobType.maxMemoryMB = 2000         #start w/ 2k then go higher if needed!
config.JobType.numCores = 1 # must match the number of threads enabled in the pset config file!
config.JobType.allowUndistributedCMSSW = True #Problems with slc7
config.JobType.maxJobRuntimeMin = 210 # max = 2750
config.JobType.pyCfgParams = ['noprint']
config.JobType.outputFiles = ['HiForestMINIAOD_PbPb2024.root']
config.JobType.inputFiles = ['CentralityTable_HFtowers200_DataPbPb2024_periHYDJETshape_run3v140x01_offline_Nominal.db']

config.section_("Data")
config.Data.inputDBS = 'global'
#config.Data.totalUnits = -1
config.Data.splitting = "FileBased"
config.Data.unitsPerJob = 5
#config.Data.allowNonValidInputDataset = True
config.Data.publication = False
config.Data.runRange = '387853-388784'
config.Data.lumiMask = 'https://cms-service-dqmdc.web.cern.ch/CAF/certification/Collisions24HI/Cert_Collisions2024_HI_387853_388784_Muon.json'   

config.section_("Site")
#config.Site.storageSite = "T3_CH_CERNBOX"
config.Site.storageSite = "T2_PT_NCG_Lisbon"
#config.Site.whitelist = ["T2_US_*","T2_CH_CERN","T1_US_*"]

# Multi crab part
def get_datasets_from_file(filename):
    with open(filename, 'r') as f:
        datasets = [line.strip() for line in f if line.strip()]
    return datasets


# Submit the jobs: 180 HIRawPrime24 PDs, ~1000 files each, average of ??? events/file
config.Data.outLFNDirBase = '/store/user/hmarques/DATA_PbPb24'


def submit_multiple_datasets(dataset_list):
    for i, dataset in enumerate(dataset_list):
        config.General.requestName = f'RawPrime{i}'
        config.Data.inputDataset = dataset
        config.Data.outputDatasetTag = config.General.requestName

        work_area = os.path.join(config.General.workArea, f"crab_{config.General.requestName}")
        if os.path.exists(work_area):
            print(f"[!] Skipping {dataset}: working area already exists -> {work_area}")
            continue

        print("Submitting CRAB job for: " + dataset)
        crabCommand('submit', config = config, dryrun=False)

# Usage:
datasets = get_datasets_from_file("./datasets_pbpb2024.txt")
submit_multiple_datasets(datasets)