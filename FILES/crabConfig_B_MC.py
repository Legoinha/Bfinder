from CRABClient.UserUtilities import config
config = config()

config.General.transferOutputs = True
config.General.workArea = 'crab_projects_B'
config.JobType.pluginName = 'Analysis'
config.JobType.maxMemoryMB = 2000
config.JobType.maxJobRuntimeMin = 60 # max = 2750
config.JobType.numCores = 1
config.JobType.pyCfgParams = ['noprint']

######################################################################################################################################################
###################################               ###################################               ###################################
######################################################################################################################################################

##PbPb
#config.JobType.psetName = 'forest_miniAOD_run3_MC_wBfinder_2023.py'
#config.Data.inputDataset = '/MC_PbPb_X3872/hmarques-prompt_X3872_to_Jpsi_Rho_phat5_miniAOD-80a77cd862f44822931af5f8ae2b9b98/USER'
#config.General.requestName = 'MC_PbPb_prompt_X3872_to_Jpsi_Rho_phat5_Bfinder'
#config.Data.outputDatasetTag =       'prompt_X3872_to_Jpsi_Rho_phat5_Bfinder'


##ppRef
config.JobType.psetName = 'Bfinder_ppRef24_MC.py'

config.Data.inputDataset = '/MC_ppRef_X/hmarques-Bplus_to_JPsiK_pthat10_prompt_miniAOD-6f03abc0b379285456b22033b16cec86/USER'
config.General.requestName = 'MC_ppRef_Bplus_to_JPsiK_pthat10'
config.Data.outputDatasetTag =        'Bplus_to_JPsiK_pthat10'


#MC
config.Data.inputDBS = 'phys03' 

######################################################################################################################################################
###################################               ###################################               ###################################
######################################################################################################################################################

config.Data.unitsPerJob = 1
config.Data.totalUnits = -1
config.Data.splitting = 'FileBased'

##########################################################################
config.Data.outLFNDirBase = '/store/user/hmarques/MC_ppRef_Bmesons/' 
config.JobType.outputFiles = ['HiForestMINIAOD_ppRefMC.root'] 
config.Data.publication = False 
#config.Site.storageSite = "T2_CH_CERN" 
config.Site.storageSite = "T3_CH_CERNBOX" 
#config.Site.storageSite = "T2_PT_NCG_Lisbon" 
##########################################################################