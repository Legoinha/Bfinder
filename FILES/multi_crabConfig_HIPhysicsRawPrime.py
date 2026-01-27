from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException
from http.client import HTTPException

# We want to put all the CRAB project directories from the tasks we submit here into one common directory.
# That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.workArea = 'crab_projects_X'
config.General.transferOutputs = True
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = "Analysis"
config.JobType.psetName = "forest_miniAOD_run3_DATA_wBfinder_2023.py"
config.JobType.maxMemoryMB = 2000         #start w/ 2k then go higher if needed!
config.JobType.numCores = 1 # must match the number of threads enabled in the pset config file!
config.JobType.allowUndistributedCMSSW = True #Problems with slc7
config.JobType.maxJobRuntimeMin = 210 # max = 2750
config.JobType.pyCfgParams = ['noprint']
config.JobType.outputFiles = ['HiForestMINIAOD.root']

config.section_("Data")
config.Data.inputDBS = 'global'
#config.Data.totalUnits = -1
config.Data.splitting = "FileBased"
config.Data.unitsPerJob = 5
#config.Data.allowNonValidInputDataset = True
config.Data.publication = False
config.Data.runRange = '374288-375823'
config.Data.lumiMask = 'https://cms-service-dqmdc.web.cern.ch/CAF/certification/Collisions23HI/Cert_Collisions2023HI_374288_375823_Muon.json'

config.section_("Site")
#config.Site.storageSite = "T3_CH_CERNBOX"
config.Site.storageSite = "T2_PT_NCG_Lisbon"
#config.Site.whitelist = ["T2_US_*","T2_CH_CERN","T1_US_*"]

# Multi crab part
def submit(config):
    try:
        crabCommand('submit', config = config, dryrun=False)
    except HTTPException as hte:
        print("Failed submitting task: %s" % (hte.headers))
    except ClientException as cle:
        print("Failed submitting task: %s" % (cle))

# Submit the jobs: 32 HIRawPrime PDs, 5.0 to 5.5k files each, average of 140k events/file
config.Data.outLFNDirBase = '/store/user/hmarques/DATA_PbPb23'

for i in range(28):   ###32

    config.General.requestName = f'RawPrime{i}'
    config.Data.inputDataset = f"/HIPhysicsRawPrime{i}/HIRun2023A-PromptReco-v2/MINIAOD"
    config.Data.outputDatasetTag = config.General.requestName

    print("Submitting CRAB job for: "+ config.Data.inputDataset)
    submit(config)