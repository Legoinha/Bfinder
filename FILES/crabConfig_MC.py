from CRABClient.UserUtilities import config
config = config()

config.General.transferOutputs = True
config.General.workArea = 'crab_projects_X'

config.JobType.pluginName = 'Analysis'
config.JobType.maxMemoryMB = 4000
config.JobType.maxJobRuntimeMin = 2000 # max = 2750       ## 
config.JobType.numCores = 2
config.JobType.pyCfgParams = ['noprint']

######################################################################################################################################################
###################################               ###################################               ###################################
######################################################################################################################################################

##PbPb 23
#config.JobType.psetName = 'forest_miniAOD_run3_MC_wBfinder_2023.py'

#config.Data.inputDataset = '/MC_PbPb_X3872/hmarques-prompt_X3872_to_Jpsi_Rho_phat5_miniAOD-80a77cd862f44822931af5f8ae2b9b98/USER'    ##<---- Small
#config.Data.inputDataset = '/MC_PbPb_X3872/hmarques-prompt_X3872_to_JPsiRho_pthat10_v1_miniAOD-5523f4f2bfa1f71c4cb2f00b79ca689f/USER'   
#config.General.requestName = 'MC_PbPb_prompt_X3872_to_Jpsi_Rho_phat5_Bfinder_large'
#config.Data.outputDatasetTag =       'prompt_X3872_to_Jpsi_Rho_phat5_Bfinder_large'

#config.Data.inputDataset = '/MC_PbPb_X3872/hmarques-prompt_PSI2S_to_Jpsi_pipi_phat5_miniAOD-80a77cd862f44822931af5f8ae2b9b98/USER'    ##<---- Small
#config.Data.inputDataset = '/MC_PbPb_X3872/hmarques-prompt_PSI2S_to_Jpsi_pipi_phat10_v1_miniAOD-5523f4f2bfa1f71c4cb2f00b79ca689f/USER'  
#config.General.requestName = 'MC_PbPb_prompt_PSI2S_to_Jpsi_pipi_phat5_Bfinder_large'
#config.Data.outputDatasetTag =       'prompt_PSI2S_to_Jpsi_pipi_phat5_Bfinder_large'




##PbPb 24
config.JobType.psetName = 'forest_miniAOD_run3_MC_wBfinder_2024.py'
config.JobType.inputFiles = ['CentralityTable_HFtowers200_DataPbPb2024_periHYDJETshape_run3v140x01_offline_Nominal.db']

config.Data.inputDataset = '/MC_PbPb2024_prompt_X/leyao-leyao-MC_PbPb2024_prompt_X_phat10_miniAOD_v1_2_set2-f532239ff5f7344180d160ae5777f4b0/USER'   
config.General.requestName = 'MC_PbPb_prompt_X3872_to_Jpsi_Rho_phat5_Bfinder_large_pbpb24'
config.Data.outputDatasetTag =       'prompt_X3872_to_Jpsi_Rho_phat5_Bfinder_large_pbpb24'

#config.Data.inputDataset = '/MC_PbPb2024_prompt_psi2S/leyao-leyao-MC_PbPb2024_prompt_psi2S_phat10_miniAOD_v1_2_set2-f532239ff5f7344180d160ae5777f4b0/USER' 
#config.General.requestName = 'MC_PbPb_prompt_PSI2S_to_Jpsi_pipi_phat5_Bfinder_large_pbpb24_pbpb24'
#config.Data.outputDatasetTag =       'prompt_PSI2S_to_Jpsi_pipi_phat5_Bfinder_large_pbpb24_pbpb24'





##ppRef
#config.JobType.psetName = 'Bfinder_ppRef24_MC.py'

#config.Data.inputDataset = '/ppRef_X3872/hmarques-nonprompt_X3872_to_Jpsi_Rho_phat5_miniAOD-b08ea5aba0caf44286efb8557bf5e709/USER'
#config.General.requestName = 'MC_ppRef_nonprompt_X3872_to_Jpsi_Rho_phat5_Bfinder'
#config.Data.outputDatasetTag =        'nonprompt_X3872_to_Jpsi_Rho_phat5_Bfinder'
#config.Data.inputDataset = '/ppRef_X3872/hmarques-nonprompt_PSI2S_to_Jpsi_pipi_phat5_miniAOD-b08ea5aba0caf44286efb8557bf5e709/USER'
#config.General.requestName = 'MC_ppRef_nonprompt_PSI2S_to_Jpsi_pipi_phat5_Bfinder'
#config.Data.outputDatasetTag =        'nonprompt_PSI2S_to_Jpsi_pipi_phat5_Bfinder'

#config.Data.inputDataset = '/ppRef_X3872/hmarques-prompt_PSI2S_to_Jpsi_pipi_phat5_miniAOD-b08ea5aba0caf44286efb8557bf5e709/USER' ##<---- Small
#config.Data.inputDataset = '/MC_ppRef_X/hmarques-PSI2S_to_JPsiPiPi_pthat10_prompt_miniAOD-6f03abc0b379285456b22033b16cec86/USER' 
#config.General.requestName = 'MC_ppRef_prompt_PSI2S_to_Jpsi_pipi_phat5_Bfinder_small'
#config.Data.outputDatasetTag =        'prompt_PSI2S_to_Jpsi_pipi_phat5_Bfinder'

#config.Data.inputDataset = '/ppRef_X3872/hmarques-prompt_X3872_to_Jpsi_Rho_phat5_miniAOD-b08ea5aba0caf44286efb8557bf5e709/USER'   ## <---- Small
#config.Data.inputDataset = '/MC_ppRef_X/hmarques-X3872_prompt_to_JPsiRho_pthat10_miniAOD-6f03abc0b379285456b22033b16cec86/USER'
#config.General.requestName = 'MC_ppRef_prompt_X3872_to_Jpsi_Rho_phat5_Bfinder'
#config.Data.outputDatasetTag =        'prompt_X3872_to_Jpsi_Rho_phat5_Bfinder'

#MC

######################################################################################################################################################
###################################               ###################################               ###################################
######################################################################################################################################################

config.Data.inputDBS = 'phys03' 
config.Data.unitsPerJob = 1                      #### FOR pp use 10 per job !!! for 500 min jobs
config.Data.totalUnits = -1
config.Data.splitting = 'FileBased'

config.Data.ignoreLocality = True      ## only when necessay (to speed up job processing)
config.Site.whitelist = [
    'T2_CH_CERN','T2_BE_IIHE','T2_DE_DESY','T2_DE_RWTH','T2_ES_CIEMAT',
    'T2_IT_Bari','T2_IT_Legnaro','T2_IT_Rome','T2_UK_London_Brunel',
    'T2_US_Caltech','T2_US_Florida','T2_US_MIT','T2_US_Nebraska','T2_US_Purdue','T2_US_UCSD','T2_US_Wisconsin'
]

##########################################################################
config.Data.outLFNDirBase = '/store/user/hmarques/MC_PbPb23_X3872/' 
config.JobType.outputFiles = ['HiForestMINIAOD_MC.root'] 
config.Data.publication = False 
#config.Site.storageSite = "T2_CH_CERN" 
#config.Site.storageSite = "T3_CH_CERNBOX" 
config.Site.storageSite = "T2_PT_NCG_Lisbon" 
##########################################################################