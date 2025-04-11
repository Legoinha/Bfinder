Setup the envoriment for
**2024/2023 pp/PbPb data/MC** from miniAOD
Ref: https://twiki.cern.ch/twiki/bin/viewauth/CMS/HiForestSetup

To setup Bfinder:
=====
```
cmsrel CMSSW_14_1_4_patch5 #
cd CMSSW_14_1_4_patch5/src
cmsenv
git cms-merge-topic CmsHI:forest_CMSSW_14_1_X
git clone -b Dfinder_14XX_miniAOD https://github.com/Legoinha/Bfinder.git --depth 1
scram b -j4
cp Bfinder/FILES/* .   
```

To run:
=====

```
cmsRun forest_miniAOD_run3_DATA_wBfinder_2023.py   # taking data as an example
```




If a (basic) config. file is needed the steps bellow show how to generate one

```
cd $CMSSW_BASE/src
cmsenv
git clone -b Dfinder_14XX_miniAOD https://github.com/Legoinha/Bfinder.git --depth 1
source Bfinder/test/DnBfinder_to_Forest.sh
scram b -j4
cp HeavyIonsAnalysis/Configuration/test/forest_miniAOD_run3_DATA_wDfinder.py . # taking data as an example
```

