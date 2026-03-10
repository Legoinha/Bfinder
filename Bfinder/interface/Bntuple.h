// vim:set ts=4 sw=4 fdm=marker et:
#ifndef _BNTUPLE_H_
#define _BNTUPLE_H_
#include "format.h"

class BntupleBranches
{//{{{
public:
  float midmass[7] = {0,         0,         KSHORT_MASS, KSTAR_MASS, KSTAR_MASS, PHI_MASS,  0};

  //EvtInfo
  int      RunNo;
  int      EvtNo;
  int      LumiNo;
  int      Bsize;
  int      CentBin;   // centrality bin
  int      Jsize;
  float    PVx;
  float    PVy;
  float    PVz;
  float    PVxE;
  float    PVyE;
  float    PVzE;
  float    PVnchi2;
  float    PVchi2;
  float    BSx;
  float    BSy;
  float    BSz;
  float    BSxErr;
  float    BSyErr;
  float    BSzErr;
  float    BSdxdz;
  float    BSdydz;
  float    BSdxdzErr;
  float    BSdydzErr;
  float    BSWidthX;
  float    BSWidthXErr;
  float    BSWidthY;
  float    BSWidthYErr;
  int      nChargedTracks;
  int      nSelectedChargedTracks;
  
  //BInfo
  int       Bindex[MAX_XB];
  int       Btype[MAX_XB];
  float     Bmass[MAX_XB];
  float     Bmass_unfitted[MAX_XB];
  float     Bpt[MAX_XB];
  float     Beta[MAX_XB];
  float     Bphi[MAX_XB];
  float     By[MAX_XB];
  float     BvtxX[MAX_XB];
  float     BvtxY[MAX_XB];
  float     Bd0[MAX_XB];
  float     Bd0Err[MAX_XB];
  float     Bdxyz[MAX_XB];
  float     BdxyzErr[MAX_XB];
  float     Bchi2ndf[MAX_XB];
  float     Bchi2Prob[MAX_XB];
  float     Bdtheta[MAX_XB];
  float     Bcos_dtheta[MAX_XB];
  float     BLxy[MAX_XB];
  float     BlxyBS[MAX_XB];
  float     BlxyBSErr[MAX_XB];
  float     BMaxDoca[MAX_XB];
  float     Balpha[MAX_XB];
  float     BsvpvDistance[MAX_XB];
  float     BsvpvDisErr[MAX_XB];
  float     BsvpvDistance_2D[MAX_XB];
  float     BsvpvDisErr_2D[MAX_XB];
  float     Bnorm_svpvDistance[MAX_XB];
  float     Bnorm_svpvDistance_2D[MAX_XB];

  int       Bisbestchi2[MAX_XB];
  float     BQvalue[MAX_XB];
  float     BQvalueuj[MAX_XB];
  float     BQvaluemumu[MAX_XB];
  
  //BInfo.muonInfo
  float     Bmu1pt[MAX_XB];
  float     Bmu2pt[MAX_XB];
  float     Bmu1p[MAX_XB];
  float     Bmu2p[MAX_XB];
  float     Bmu1eta[MAX_XB];
  float     Bmu2eta[MAX_XB];
  float     Bmu1phi[MAX_XB];
  float     Bmu2phi[MAX_XB];
  float     Bmu1y[MAX_XB];
  float     Bmu2y[MAX_XB];
  float     Bmu1dzPV[MAX_XB];
  float     Bmu2dzPV[MAX_XB];
  float     Bmu1dxyPV[MAX_XB];
  float     Bmu2dxyPV[MAX_XB];
  float     Bmu1normchi2[MAX_XB];
  float     Bmu2normchi2[MAX_XB];
  float     Bmu1Chi2ndf[MAX_XB];
  float     Bmu2Chi2ndf[MAX_XB];
  int       Bmu1muqual[MAX_XB];
  int       Bmu2muqual[MAX_XB];
  bool      Bmu1TrackerMuArbitrated[MAX_XB];
  bool      Bmu2TrackerMuArbitrated[MAX_XB];
  bool      Bmu1isTrackerMuon[MAX_XB];
  bool      Bmu2isTrackerMuon[MAX_XB];
  bool      Bmu1isGlobalMuon[MAX_XB];
  bool      Bmu2isGlobalMuon[MAX_XB];
  bool      Bmu1TMOneStationTight[MAX_XB];
  bool      Bmu2TMOneStationTight[MAX_XB];
  int       Bmu1striphit[MAX_XB];
  int       Bmu2striphit[MAX_XB];
  int       Bmu1pixelhit[MAX_XB];
  int       Bmu2pixelhit[MAX_XB];
  int       Bmu1trackerhit[MAX_XB];
  int       Bmu2trackerhit[MAX_XB];
  int       Bmu1InPixelLayer[MAX_XB];
  int       Bmu2InPixelLayer[MAX_XB];
  int       Bmu1InStripLayer[MAX_XB];
  int       Bmu2InStripLayer[MAX_XB];
  int       Bmu1InTrackerLayer[MAX_XB];
  int       Bmu2InTrackerLayer[MAX_XB];
  int       Bmu1TrkQuality[MAX_XB];
  int       Bmu2TrkQuality[MAX_XB];
  bool      Bmu1highPurity[MAX_XB];
  bool      Bmu2highPurity[MAX_XB];
  bool      Bmu1SoftMuID[MAX_XB];
  bool      Bmu2SoftMuID[MAX_XB];
  bool      Bmu1HybridSoftMuID[MAX_XB];
  bool      Bmu2HybridSoftMuID[MAX_XB];  
  bool      Bmu1isAcc[MAX_XB];
  bool      Bmu2isAcc[MAX_XB];
  float     Bmu1TrgMatchFilterE[MAX_XB];
  float     Bmu1TrgMatchFilterPt[MAX_XB];
  float     Bmu1TrgMatchFilterEta[MAX_XB];
  float     Bmu1TrgMatchFilterPhi[MAX_XB];
  bool      Bmu1isTriggered[MAX_XB];
  float     Bmu2TrgMatchFilterE[MAX_XB];
  float     Bmu2TrgMatchFilterPt[MAX_XB];
  float     Bmu2TrgMatchFilterEta[MAX_XB];
  float     Bmu2TrgMatchFilterPhi[MAX_XB];
  bool      Bmu2isTriggered[MAX_XB];
  
  //BInfo.mumuInfo
  float      Bmumumass[MAX_XB];
  float      Bmumueta[MAX_XB];
  float      Bmumuphi[MAX_XB];
  float      Bmumuy[MAX_XB];
  float      Bmumupt[MAX_XB];
  
  //BInfo.ujInfo
  float     Bujmass[MAX_XB];
  float     BujvProb[MAX_XB];
  float     Bujpt[MAX_XB];
  float     Bujeta[MAX_XB];
  float     Bujphi[MAX_XB];
  float     Bujy[MAX_XB];
  float     Bujlxy[MAX_XB];
  
  //BInfo.trkInfo
  int       Btrk1Idx;
  int       Btrk2Idx;
  float     Btrk1Pt[MAX_XB];
  float     Btrk2Pt[MAX_XB];
  float     BtrkPtimb[MAX_XB];

  float     Btrk1Eta[MAX_XB];
  float     Btrk2Eta[MAX_XB];
  float     Btrk1Phi[MAX_XB];
  float     Btrk2Phi[MAX_XB];
  float     Btrk1PtErr[MAX_XB];
  float     Btrk2PtErr[MAX_XB];
  float     Btrk1EtaErr[MAX_XB];
  float     Btrk2EtaErr[MAX_XB];
  float     Btrk1PhiErr[MAX_XB];
  float     Btrk2PhiErr[MAX_XB];
  float     Btrk1Y[MAX_XB];
  float     Btrk2Y[MAX_XB];
  float     Btrk1Dz[MAX_XB];
  float     Btrk2Dz[MAX_XB];
  float     Btrk1DzError[MAX_XB];
  float     Btrk2DzError[MAX_XB];
  float     Btrk1Dxy[MAX_XB];
  float     Btrk2Dxy[MAX_XB];
  float     Bnorm_trk1Dxy[MAX_XB];
  float     Bnorm_trk2Dxy[MAX_XB];
  float     Bnorm_trk1Dz[MAX_XB];
  float     Bnorm_trk2Dz[MAX_XB];

  float     Btrk1DxyError[MAX_XB];
  float     Btrk2DxyError[MAX_XB];
  float     Btrk1Dz1[MAX_XB];
  float     Btrk2Dz1[MAX_XB];
  float     Btrk1DzError1[MAX_XB];
  float     Btrk2DzError1[MAX_XB];
  float     Btrk1Dxy1[MAX_XB];
  float     Btrk2Dxy1[MAX_XB];
  float     Btrk1DxyError1[MAX_XB];
  float     Btrk2DxyError1[MAX_XB];
  float     Btrk1PixelHit[MAX_XB];
  float     Btrk2PixelHit[MAX_XB];
  float     Btrk1StripHit[MAX_XB];
  float     Btrk2StripHit[MAX_XB];
  float     Btrk1nPixelLayer[MAX_XB];
  float     Btrk2nPixelLayer[MAX_XB];
  float     Btrk1nStripLayer[MAX_XB];
  float     Btrk2nStripLayer[MAX_XB];
  float     Btrk1Chi2ndf[MAX_XB];
  float     Btrk2Chi2ndf[MAX_XB];
  float     Btrk1MVAVal[MAX_XB];
  float     Btrk2MVAVal[MAX_XB];
  int       Btrk1Algo[MAX_XB];
  int       Btrk2Algo[MAX_XB];
  int       Btrk1originalAlgo[MAX_XB];
  int       Btrk2originalAlgo[MAX_XB];
  bool      Btrk1highPurity[MAX_XB];
  bool      Btrk2highPurity[MAX_XB];
  int       Btrk1Quality[MAX_XB];
  int       Btrk2Quality[MAX_XB];
  float     Btrk1dR[MAX_XB];
  float     Btrk2dR[MAX_XB];

  int       BtrkLH[MAX_XB];
  float     BtrkLPt[MAX_XB];
  float     BtrkHPt[MAX_XB];
  float     BtrkLPhi[MAX_XB];
  float     BtrkHPhi[MAX_XB];
  float     BtrkLEta[MAX_XB];
  float     BtrkHEta[MAX_XB];
  float     BtrkLDxy1[MAX_XB];
  float     BtrkHDxy1[MAX_XB];
  float     BtrkLDxyError1[MAX_XB];
  float     BtrkHDxyError1[MAX_XB];
  float     BtrkLDz1[MAX_XB];
  float     BtrkHDz1[MAX_XB];
  float     BtrkLDzError1[MAX_XB];
  float     BtrkHDzError1[MAX_XB];

  //BInfo.tktkInfo
  float     Btktkmass[MAX_XB];
  float     BtktkvProb[MAX_XB];
  float     Btktkpt[MAX_XB];
  float     Btktketa[MAX_XB];
  float     Btktkphi[MAX_XB];
  float     Btktky[MAX_XB];
  float     Bdoubletmass[MAX_XB];
  float     Bdoubletpt[MAX_XB];
  float     Bdoubleteta[MAX_XB];
  float     Bdoubletphi[MAX_XB];
  float     Bdoublety[MAX_XB];
  
  //BInfo.genInfo
  float     Bgen[MAX_XB];
  int       BgenIndex[MAX_XB];
  int       BgenpdgId[MAX_XB];
  float     Bgenmass[MAX_XB];
  float     Bgenpt[MAX_XB];
  int       BgencollisionId[MAX_XB];
  float     Bgeneta[MAX_XB];
  float     Bgenphi[MAX_XB];
  float     Bgeny[MAX_XB];
  
  int      Jindex[MAX_XB];
  float    Jmass[MAX_XB];
  float    Jmass_unfitted[MAX_XB];
  float    Jpt[MAX_XB];
  float    Jeta[MAX_XB];
  float    Jphi[MAX_XB];
  float    Jy[MAX_XB];
  float    JvtxX[MAX_XB];
  float    JvtxY[MAX_XB];
  float    Jd0[MAX_XB];
  float    Jdxyz[MAX_XB];
  float    Jchi2ndf[MAX_XB];
  float    Jchi2cl[MAX_XB];
  float    Jdtheta[MAX_XB];
  float    Jlxy[MAX_XB];
  float    JlxyBS[MAX_XB];
  
  //JInfo.muonInfo
  float    Jmu1pt[MAX_XB];
  float    Jmu2pt[MAX_XB];
  float    Jmu1p[MAX_XB];
  float    Jmu2p[MAX_XB];
  float    Jmu1eta[MAX_XB];
  float    Jmu2eta[MAX_XB];
  float    Jmu1phi[MAX_XB];
  float    Jmu2phi[MAX_XB];
  float    Jmu1y[MAX_XB];
  float    Jmu2y[MAX_XB];
  float    Jmu1dzPV[MAX_XB];
  float    Jmu2dzPV[MAX_XB];
  float    Jmu1dxyPV[MAX_XB];
  float    Jmu2dxyPV[MAX_XB];
  float    Jmu1normchi2[MAX_XB];
  float    Jmu2normchi2[MAX_XB];
  float    Jmu1Chi2ndf[MAX_XB];
  float    Jmu2Chi2ndf[MAX_XB];
  int      Jmu1muqual[MAX_XB];
  int      Jmu2muqual[MAX_XB];
  bool     Jmu1TrackerMuArbitrated[MAX_XB];
  bool     Jmu2TrackerMuArbitrated[MAX_XB];
  bool     Jmu1isTrackerMuon[MAX_XB];
  bool     Jmu2isTrackerMuon[MAX_XB];
  bool     Jmu1isGlobalMuon[MAX_XB];
  bool     Jmu2isGlobalMuon[MAX_XB];
  bool     Jmu1TMOneStationTight[MAX_XB];
  bool     Jmu2TMOneStationTight[MAX_XB];
  int      Jmu1striphit[MAX_XB];
  int      Jmu2striphit[MAX_XB];
  int      Jmu1pixelhit[MAX_XB];
  int      Jmu2pixelhit[MAX_XB];
  int      Jmu1trackerhit[MAX_XB];
  int      Jmu2trackerhit[MAX_XB];
  int      Jmu1InPixelLayer[MAX_XB];
  int      Jmu2InPixelLayer[MAX_XB];
  int      Jmu1InStripLayer[MAX_XB];
  int      Jmu2InStripLayer[MAX_XB];
  int      Jmu1InTrackerLayer[MAX_XB];
  int      Jmu2InTrackerLayer[MAX_XB];
  int      Jmu1TrkQuality[MAX_XB];
  int      Jmu2TrkQuality[MAX_XB];
  bool     Jmu1highPurity[MAX_XB];
  bool     Jmu2highPurity[MAX_XB];
  bool     Jmu1SoftMuID[MAX_XB];
  bool     Jmu2SoftMuID[MAX_XB];
  bool     Jmu1isAcc[MAX_XB];
  bool     Jmu2isAcc[MAX_XB];
  float    Jmu1TrgMatchFilterE[MAX_XB];
  float    Jmu1TrgMatchFilterPt[MAX_XB];
  float    Jmu1TrgMatchFilterEta[MAX_XB];
  float    Jmu1TrgMatchFilterPhi[MAX_XB];
  bool     Jmu1isTriggered[MAX_XB];
  float    Jmu2TrgMatchFilterE[MAX_XB];
  float    Jmu2TrgMatchFilterPt[MAX_XB];
  float    Jmu2TrgMatchFilterEta[MAX_XB];
  float    Jmu2TrgMatchFilterPhi[MAX_XB];
  bool     Jmu2isTriggered[MAX_XB];
  
  float    Jgen[MAX_XB];
  int      JgenIndex[MAX_XB];
  float    Jgenpt[MAX_XB];
  int      JgencollisionId[MAX_XB];
  float    Jgeneta[MAX_XB];
  float    Jgenphi[MAX_XB];
  float    Jgeny[MAX_XB];

  void buildBranch(TTree* nt, Bool_t isJpsi=false)
  {
    //EvtInfo
    nt->Branch("RunNo",&RunNo);
    nt->Branch("CentBin", &CentBin);  //centrality
    nt->Branch("EvtNo",&EvtNo);
    nt->Branch("LumiNo",&LumiNo);
    nt->Branch("PVx",&PVx);
    nt->Branch("PVy",&PVy);
    nt->Branch("PVz",&PVz);
    nt->Branch("PVxE",&PVxE);
    nt->Branch("PVyE",&PVyE);
    nt->Branch("PVzE",&PVzE);
    nt->Branch("PVnchi2",&PVnchi2);
    //nt->Branch("PVchi2",&PVchi2);
    /*
    nt->Branch("BSx",&BSx);
    nt->Branch("BSy",&BSy);
    nt->Branch("BSz",&BSz);
    nt->Branch("BSxErr",&BSxErr);
    nt->Branch("BSyErr",&BSyErr);
    nt->Branch("BSzErr",&BSzErr);
    nt->Branch("BSdxdz",&BSdxdz);
    nt->Branch("BSdydz",&BSdydz);
    nt->Branch("BSdxdzErr",&BSdxdzErr);
    nt->Branch("BSdydzErr",&BSdydzErr);
    nt->Branch("BSWidthX",&BSWidthX);
    nt->Branch("BSWidthXErr",&BSWidthXErr);
    nt->Branch("BSWidthY",&BSWidthY);
    nt->Branch("BSWidthYErr",&BSWidthYErr);
    */
    nt->Branch("nChargedTracks",&nChargedTracks);
    nt->Branch("nSelectedChargedTracks",&nSelectedChargedTracks);
    
    if(isJpsi)
      {
        nt->Branch("Jsize",&Jsize);
        nt->Branch("Jindex",Jindex,"Jindex[Jsize]/I");
        nt->Branch("Jmass",Jmass,"Jmass[Jsize]/F");
        nt->Branch("Jmass_unfitted",Jmass_unfitted,"Jmass_unfitted[Jsize]/F");
        nt->Branch("Jpt",Jpt,"Jpt[Jsize]/F");
        nt->Branch("Jeta",Jeta,"Jeta[Jsize]/F");
        nt->Branch("Jphi",Jphi,"Jphi[Jsize]/F");
        nt->Branch("Jy",Jy,"Jy[Jsize]/F");
        nt->Branch("JvtxX",JvtxX,"JvtxX[Jsize]/F");
        nt->Branch("JvtxY",JvtxY,"JvtxY[Jsize]/F");
        nt->Branch("Jd0",Jd0,"Jd0[Jsize]/F");
        nt->Branch("Jdxyz",Jdxyz,"Jdxyz[Jsize]/F");
        nt->Branch("Jchi2ndf",Jchi2ndf,"Jchi2ndf[Jsize]/F");
        nt->Branch("Jchi2cl",Jchi2cl,"Jchi2cl[Jsize]/F");
        nt->Branch("Jdtheta",Jdtheta,"Jdtheta[Jsize]/F");
        nt->Branch("Jlxy",Jlxy,"Jlxy[Jsize]/F");
        nt->Branch("JlxyBS",JlxyBS,"JlxyBS[Jsize]/F");
        
        nt->Branch("Jmu1pt",Jmu1pt,"Jmu1pt[Jsize]/F");
        nt->Branch("Jmu2pt",Jmu2pt,"Jmu2pt[Jsize]/F");
        nt->Branch("Jmu1p",Jmu1p,"Jmu1p[Jsize]/F");
        nt->Branch("Jmu2p",Jmu2p,"Jmu2p[Jsize]/F");
        nt->Branch("Jmu1eta",Jmu1eta,"Jmu1eta[Jsize]/F");
        nt->Branch("Jmu2eta",Jmu2eta,"Jmu2eta[Jsize]/F");
        nt->Branch("Jmu1phi",Jmu1phi,"Jmu1phi[Jsize]/F");
        nt->Branch("Jmu2phi",Jmu2phi,"Jmu2phi[Jsize]/F");
        nt->Branch("Jmu1y",Jmu1y,"Jmu1y[Jsize]/F");
        nt->Branch("Jmu2y",Jmu2y,"Jmu2y[Jsize]/F");
        nt->Branch("Jmu1dzPV",Jmu1dzPV,"Jmu1dzPV[Jsize]/F");
        nt->Branch("Jmu2dzPV",Jmu2dzPV,"Jmu2dzPV[Jsize]/F");
        nt->Branch("Jmu1dxyPV",Jmu1dxyPV,"Jmu1dxyPV[Jsize]/F");
        nt->Branch("Jmu2dxyPV",Jmu2dxyPV,"Jmu2dxyPV[Jsize]/F");
        nt->Branch("Jmu1normchi2",Jmu1normchi2,"Jmu1normchi2[Jsize]/F");
        nt->Branch("Jmu2normchi2",Jmu2normchi2,"Jmu2normchi2[Jsize]/F");
        nt->Branch("Jmu1Chi2ndf",Jmu1Chi2ndf,"Jmu1Chi2ndf[Jsize]/F");
        nt->Branch("Jmu2Chi2ndf",Jmu2Chi2ndf,"Jmu2Chi2ndf[Jsize]/F");
        nt->Branch("Jmu1muqual",Jmu1muqual,"Jmu1muqual[Jsize]/I");
        nt->Branch("Jmu2muqual",Jmu2muqual,"Jmu2muqual[Jsize]/I");
        nt->Branch("Jmu1TrackerMuArbitrated",Jmu1TrackerMuArbitrated,"Jmu1TrackerMuArbitrated[Jsize]/O");
        nt->Branch("Jmu2TrackerMuArbitrated",Jmu2TrackerMuArbitrated,"Jmu2TrackerMuArbitrated[Jsize]/O");
        nt->Branch("Jmu1isTrackerMuon",Jmu1isTrackerMuon,"Jmu1isTrackerMuon[Jsize]/O");
        nt->Branch("Jmu2isTrackerMuon",Jmu2isTrackerMuon,"Jmu2isTrackerMuon[Jsize]/O");
        nt->Branch("Jmu1isGlobalMuon",Jmu1isGlobalMuon,"Jmu1isGlobalMuon[Jsize]/O");
        nt->Branch("Jmu2isGlobalMuon",Jmu2isGlobalMuon,"Jmu2isGlobalMuon[Jsize]/O");
        nt->Branch("Jmu1TMOneStationTight",Jmu1TMOneStationTight,"Jmu1TMOneStationTight[Jsize]/O");
        nt->Branch("Jmu2TMOneStationTight",Jmu2TMOneStationTight,"Jmu2TMOneStationTight[Jsize]/O");
        nt->Branch("Jmu1striphit",Jmu1striphit,"Jmu1striphit[Jsize]/I");
        nt->Branch("Jmu2striphit",Jmu2striphit,"Jmu2striphit[Jsize]/I");
        nt->Branch("Jmu1pixelhit",Jmu1pixelhit,"Jmu1pixelhit[Jsize]/I");
        nt->Branch("Jmu2pixelhit",Jmu2pixelhit,"Jmu2pixelhit[Jsize]/I");
        nt->Branch("Jmu1trackerhit",Jmu1trackerhit,"Jmu1trackerhit[Jsize]/I");
        nt->Branch("Jmu2trackerhit",Jmu2trackerhit,"Jmu2trackerhit[Jsize]/I");
        nt->Branch("Jmu1InPixelLayer",Jmu1InPixelLayer,"Jmu1InPixelLayer[Jsize]/I");
        nt->Branch("Jmu2InPixelLayer",Jmu2InPixelLayer,"Jmu2InPixelLayer[Jsize]/I");
        nt->Branch("Jmu1InStripLayer",Jmu1InStripLayer,"Jmu1InStripLayer[Jsize]/I");
        nt->Branch("Jmu2InStripLayer",Jmu2InStripLayer,"Jmu2InStripLayer[Jsize]/I");
        nt->Branch("Jmu1InTrackerLayer",Jmu1InTrackerLayer,"Jmu1InTrackerLayer[Jsize]/I");
        nt->Branch("Jmu2InTrackerLayer",Jmu2InTrackerLayer,"Jmu2InTrackerLayer[Jsize]/I");
        nt->Branch("Jmu1TrkQuality",Jmu1TrkQuality,"Jmu1TrkQuality[Jsize]/I");
        nt->Branch("Jmu2TrkQuality",Jmu2TrkQuality,"Jmu2TrkQuality[Jsize]/I");
        nt->Branch("Jmu1highPurity",Jmu1highPurity,"Jmu1highPurity[Jsize]/O");
        nt->Branch("Jmu2highPurity",Jmu2highPurity,"Jmu2highPurity[Jsize]/O");
        nt->Branch("Jmu1SoftMuID",Jmu1SoftMuID,"Jmu1SoftMuID[Jsize]/O");
        nt->Branch("Jmu2SoftMuID",Jmu2SoftMuID,"Jmu2SoftMuID[Jsize]/O");
        nt->Branch("Jmu1isAcc",Jmu1isAcc,"Jmu1isAcc[Jsize]/O");
        nt->Branch("Jmu2isAcc",Jmu2isAcc,"Jmu2isAcc[Jsize]/O");
        nt->Branch("Jmu1TrgMatchFilterE"  ,Bmu1TrgMatchFilterE,  "Bmu1TrgMatchFilterE[Jsize]/F");
        nt->Branch("Jmu1TrgMatchFilterPt" ,Bmu1TrgMatchFilterPt, "Bmu1TrgMatchFilterPt[Jsize]/F");
        nt->Branch("Jmu1TrgMatchFilterEta",Jmu1TrgMatchFilterEta,"Jmu1TrgMatchFilterEta[Jsize]/F");
        nt->Branch("Jmu1TrgMatchFilterPhi",Jmu1TrgMatchFilterPhi,"Jmu1TrgMatchFilterPhi[Jsize]/F");
        nt->Branch("Jmu1isTriggered",Jmu1isTriggered,"Jmu1isTriggered[Jsize]/O");
        nt->Branch("Jmu2TrgMatchFilterE"  ,Bmu2TrgMatchFilterE,  "Bmu2TrgMatchFilterE[Jsize]/F");
        nt->Branch("Jmu2TrgMatchFilterPt" ,Bmu2TrgMatchFilterPt, "Bmu2TrgMatchFilterPt[Jsize]/F");
        nt->Branch("Jmu2TrgMatchFilterEta",Jmu2TrgMatchFilterEta,"Jmu2TrgMatchFilterEta[Jsize]/F");
        nt->Branch("Jmu2TrgMatchFilterPhi",Jmu2TrgMatchFilterPhi,"Jmu2TrgMatchFilterPhi[Jsize]/F");
        nt->Branch("Jmu2isTriggered",Jmu2isTriggered,"Jmu2isTriggered[Jsize]/O");

        nt->Branch("Jgen",Jgen,"Jgen[Jsize]/F");
        nt->Branch("JgenIndex",JgenIndex,"JgenIndex[Jsize]/I");
        nt->Branch("Jgenpt",Jgenpt,"Jgenpt[Jsize]/F");
        nt->Branch("JgencollisionId",JgencollisionId,"JgencollisionId[Jsize]/I");
        nt->Branch("Jgeny",Jgeny,"Jgeny[Jsize]/F");
        nt->Branch("Jgeneta",Jgeneta,"Jgeneta[Jsize]/F");
        nt->Branch("Jgenphi",Jgenphi,"Jgenphi[Jsize]/F");
      }
    else
      {
        nt->Branch("Bsize",&Bsize);
        //BInfo
        nt->Branch("Bindex",Bindex,"Bindex[Bsize]/I");
        nt->Branch("Btype",Btype,"Btype[Bsize]/I");
        nt->Branch("Bmass",Bmass,"Bmass[Bsize]/F");
        //nt->Branch("Bmass_unfitted",Bmass_unfitted,"Bmass_unfitted[Bsize]/F");
        nt->Branch("Bpt",Bpt,"Bpt[Bsize]/F");
        //nt->Branch("Beta",Beta,"Beta[Bsize]/F");
        //nt->Branch("Bphi",Bphi,"Bphi[Bsize]/F");
        nt->Branch("By",By,"By[Bsize]/F");
        nt->Branch("BvtxX",BvtxX,"BvtxX[Bsize]/F");
        nt->Branch("BvtxY",BvtxY,"BvtxY[Bsize]/F");
        nt->Branch("Bd0",Bd0,"Bd0[Bsize]/F");
        nt->Branch("Bd0Err",Bd0Err,"Bd0Err[Bsize]/F");
        nt->Branch("Bdxyz",Bdxyz,"Bdxyz[Bsize]/F");
        nt->Branch("BdxyzErr",BdxyzErr,"BdxyzErr[Bsize]/F");
        nt->Branch("Bchi2ndf",Bchi2ndf,"Bchi2ndf[Bsize]/F");
        nt->Branch("Bchi2Prob",Bchi2Prob,"Bchi2Prob[Bsize]/F");
        nt->Branch("Bdtheta",Bdtheta,"Bdtheta[Bsize]/F");
        nt->Branch("Bcos_dtheta",Bcos_dtheta,"Bcos_dtheta[Bsize]/F");

        nt->Branch("BLxy",BLxy,"BLxy[Bsize]/F");
        //nt->Branch("BlxyBS",BlxyBS,"BlxyBS[Bsize]/F");
        //nt->Branch("BlxyBSErr",BlxyBSErr,"BlxyBSErr[Bsize]/F");
        nt->Branch("Balpha",Balpha,"Balpha[Bsize]/F");
        nt->Branch("BsvpvDistance",BsvpvDistance,"BsvpvDistance[Bsize]/F");
        nt->Branch("BsvpvDisErr",BsvpvDisErr,"BsvpvDisErr[Bsize]/F");
        nt->Branch("BsvpvDistance_2D",BsvpvDistance_2D,"BsvpvDistance_2D[Bsize]/F");
        nt->Branch("BsvpvDisErr_2D",BsvpvDisErr_2D,"BsvpvDisErr_2D[Bsize]/F");
        nt->Branch("Bnorm_svpvDistance",Bnorm_svpvDistance,"Bnorm_svpvDistance[Bsize]/F");
        nt->Branch("Bnorm_svpvDistance_2D",Bnorm_svpvDistance_2D,"Bnorm_svpvDistance_2D[Bsize]/F");

        /*
        nt->Branch("BMaxDoca",BMaxDoca,"BMaxDoca[Bsize]/F");
        nt->Branch("Bisbestchi2",Bisbestchi2,"Bisbestchi2[Bsize]/I");
        */
        nt->Branch("BQvalue",BQvalue,"BQvalue[Bsize]/F");
        nt->Branch("BQvalueuj",BQvalueuj,"BQvalueuj[Bsize]/F");
       

        //BInfo.trkInfo
        nt->Branch("Btrk1Pt",Btrk1Pt,"Btrk1Pt[Bsize]/F");
        nt->Branch("Btrk2Pt",Btrk2Pt,"Btrk2Pt[Bsize]/F");
        nt->Branch("BtrkPtimb",BtrkPtimb,"BtrkPtimb[Bsize]/F");
        nt->Branch("Btrk1Eta",Btrk1Eta,"Btrk1Eta[Bsize]/F");  
        nt->Branch("Btrk2Eta",Btrk2Eta,"Btrk2Eta[Bsize]/F");  
        nt->Branch("Btrk1Phi",Btrk1Phi,"Btrk1Phi[Bsize]/F");  
        nt->Branch("Btrk2Phi",Btrk2Phi,"Btrk2Phi[Bsize]/F");  
        nt->Branch("Btrk1PtErr",Btrk1PtErr,"Btrk1PtErr[Bsize]/F");  
        nt->Branch("Btrk2PtErr",Btrk2PtErr,"Btrk2PtErr[Bsize]/F");
        //nt->Branch("Btrk1EtaErr",Btrk1EtaErr,"Btrk1EtaErr[Bsize]/F");
        //nt->Branch("Btrk2EtaErr",Btrk2EtaErr,"Btrk2EtaErr[Bsize]/F");
        //nt->Branch("Btrk1PhiErr",Btrk1PhiErr,"Btrk1PhiErr[Bsize]/F");
        //nt->Branch("Btrk2PhiErr",Btrk2PhiErr,"Btrk2PhiErr[Bsize]/F");
        //nt->Branch("Btrk1Y",Btrk1Y,"Btrk1Y[Bsize]/F");  
        //nt->Branch("Btrk2Y",Btrk2Y,"Btrk2Y[Bsize]/F");
        /*  
        nt->Branch("Btrk1Dz",Btrk1Dz,"Btrk1Dz[Bsize]/F");
        nt->Branch("Btrk2Dz",Btrk2Dz,"Btrk2Dz[Bsize]/F");
        nt->Branch("Btrk1DzError",Btrk1DzError,"Btrk1DzError[Bsize]/F");
        nt->Branch("Btrk2DzError",Btrk2DzError,"Btrk2DzError[Bsize]/F");
        nt->Branch("Btrk1Dxy",Btrk1Dxy,"Btrk1Dxy[Bsize]/F");
        nt->Branch("Btrk2Dxy",Btrk2Dxy,"Btrk2Dxy[Bsize]/F");
        nt->Branch("Btrk1DxyError",Btrk1DxyError,"Btrk1DxyError[Bsize]/F");
        nt->Branch("Btrk2DxyError",Btrk2DxyError,"Btrk2DxyError[Bsize]/F");
        */
        nt->Branch("Bnorm_trk1Dxy",Bnorm_trk1Dxy,"Bnorm_trk1Dxy[Bsize]/F");
        nt->Branch("Bnorm_trk2Dxy",Bnorm_trk2Dxy,"Bnorm_trk2Dxy[Bsize]/F");
        nt->Branch("Bnorm_trk1Dz",Bnorm_trk1Dz,"Bnorm_trk1Dz[Bsize]/F");
        nt->Branch("Bnorm_trk2Dz",Bnorm_trk2Dz,"Bnorm_trk2Dz[Bsize]/F");

        //nt->Branch("Btrk1Dz1",Btrk1Dz1,"Btrk1Dz1[Bsize]/F");
        //nt->Branch("Btrk2Dz1",Btrk2Dz1,"Btrk2Dz1[Bsize]/F");
        //nt->Branch("Btrk1DzError1",Btrk1DzError1,"Btrk1DzError1[Bsize]/F");
        //nt->Branch("Btrk2DzError1",Btrk2DzError1,"Btrk2DzError1[Bsize]/F");
        //nt->Branch("Btrk1Dxy1",Btrk1Dxy1,"Btrk1Dxy1[Bsize]/F");
        //nt->Branch("Btrk2Dxy1",Btrk2Dxy1,"Btrk2Dxy1[Bsize]/F");
        //nt->Branch("Btrk1DxyError1",Btrk1DxyError1,"Btrk1DxyError1[Bsize]/F");
        //nt->Branch("Btrk2DxyError1",Btrk2DxyError1,"Btrk2DxyError1[Bsize]/F");
        
        //nt->Branch("Btrk1PixelHit",Btrk1PixelHit,"Btrk1PixelHit[Bsize]/F");
        //nt->Branch("Btrk2PixelHit",Btrk2PixelHit,"Btrk2PixelHit[Bsize]/F");
        //nt->Branch("Btrk1StripHit",Btrk1StripHit,"Btrk1StripHit[Bsize]/F");
        //nt->Branch("Btrk2StripHit",Btrk2StripHit,"Btrk2StripHit[Bsize]/F");
        nt->Branch("Btrk1nPixelLayer",Btrk1nPixelLayer,"Btrk1nPixelLayer[Bsize]/F");
        nt->Branch("Btrk2nPixelLayer",Btrk2nPixelLayer,"Btrk2nPixelLayer[Bsize]/F");
        nt->Branch("Btrk1nStripLayer",Btrk1nStripLayer,"Btrk1nStripLayer[Bsize]/F");
        nt->Branch("Btrk2nStripLayer",Btrk2nStripLayer,"Btrk2nStripLayer[Bsize]/F");
        nt->Branch("Btrk1Chi2ndf",Btrk1Chi2ndf,"Btrk1Chi2ndf[Bsize]/F");
        nt->Branch("Btrk2Chi2ndf",Btrk2Chi2ndf,"Btrk2Chi2ndf[Bsize]/F");
        
        //nt->Branch("Btrk1MVAVal",Btrk1MVAVal,"Btrk1MVAVal[Bsize]/F");
        //nt->Branch("Btrk2MVAVal",Btrk2MVAVal,"Btrk2MVAVal[Bsize]/F");
        //nt->Branch("Btrk1Algo",Btrk1Algo,"Btrk1Algo[Bsize]/I");
        //nt->Branch("Btrk2Algo",Btrk2Algo,"Btrk2Algo[Bsize]/I");
        //nt->Branch("Btrk1originalAlgo",Btrk1originalAlgo,"Btrk1originalAlgo[Bsize]/I");
        //nt->Branch("Btrk2originalAlgo",Btrk2originalAlgo,"Btrk2originalAlgo[Bsize]/I");
        nt->Branch("Btrk1highPurity",Btrk1highPurity,"Btrk1highPurity[Bsize]/O");
        nt->Branch("Btrk2highPurity",Btrk2highPurity,"Btrk2highPurity[Bsize]/O");
        //nt->Branch("Btrk1Quality",Btrk1Quality,"Btrk1Quality[Bsize]/I");
        //nt->Branch("Btrk2Quality",Btrk2Quality,"Btrk2Quality[Bsize]/I");

        nt->Branch("Btrk1dR",Btrk1dR,"Btrk1dR[Bsize]/F");
        nt->Branch("Btrk2dR",Btrk2dR,"Btrk2dR[Bsize]/F");
        
        /*
        nt->Branch("BtrkLH",BtrkLPt,"BtrkLH[Bsize]/I");
        nt->Branch("BtrkLPt",BtrkLPt,"BtrkLPt[Bsize]/F");
        nt->Branch("BtrkHPt",BtrkHPt,"BtrkHPt[Bsize]/F");
        nt->Branch("BtrkLPhi",BtrkLPhi,"BtrkLPhi[Bsize]/F");
        nt->Branch("BtrkHPhi",BtrkHPhi,"BtrkHPhi[Bsize]/F");
        nt->Branch("BtrkLEta",BtrkLEta,"BtrkLEta[Bsize]/F");
        nt->Branch("BtrkHEta",BtrkHEta,"BtrkHEta[Bsize]/F");
        nt->Branch("BtrkLDxy1",BtrkLDxy1,"BtrkLDxy1[Bsize]/F");
        nt->Branch("BtrkHDxy1",BtrkHDxy1,"BtrkHDxy1[Bsize]/F");
        nt->Branch("BtrkLDxyError1",BtrkLDxyError1,"BtrkLDxyError1[Bsize]/F");
        nt->Branch("BtrkHDxyError1",BtrkHDxyError1,"BtrkHDxyError1[Bsize]/F");
        nt->Branch("BtrkLDz1",BtrkLDz1,"BtrkLDz1[Bsize]/F");
        nt->Branch("BtrkHDz1",BtrkHDz1,"BtrkHDz1[Bsize]/F");
        nt->Branch("BtrkLDzError1",BtrkLDzError1,"BtrkLDzError1[Bsize]/F");
        nt->Branch("BtrkHDzError1",BtrkHDzError1,"BtrkHDzError1[Bsize]/F");
        */

        //BInfo.tktkInfo
        nt->Branch("Btktkmass",Btktkmass,"Btktkmass[Bsize]/F");
        nt->Branch("BtktkvProb",BtktkvProb,"BtktkvProb[Bsize]/F");
        nt->Branch("Btktkpt",Btktkpt,"Btktkpt[Bsize]/F");
        //nt->Branch("Btktketa",Btktketa,"Btktketa[Bsize]/F");
        //nt->Branch("Btktkphi",Btktkphi,"Btktkphi[Bsize]/F");
        //nt->Branch("Btktky",Btktky,"Btktky[Bsize]/F");
        nt->Branch("Bdoubletmass",Bdoubletmass,"Bdoubletmass[Bsize]/F");
        //nt->Branch("Bdoubletpt",Bdoubletpt,"Bdoubletpt[Bsize]/F");
        //nt->Branch("Bdoubleteta",Bdoubleteta,"Bdoubleteta[Bsize]/F");  
        //nt->Branch("Bdoubletphi",Bdoubletphi,"Bdoubletphi[Bsize]/F");  
        //nt->Branch("Bdoublety",Bdoublety,"Bdoublety[Bsize]/F");
        
        //BInfo.muonInfo
        nt->Branch("Bmu1pt",Bmu1pt,"Bmu1pt[Bsize]/F");
        nt->Branch("Bmu2pt",Bmu2pt,"Bmu2pt[Bsize]/F");
        
        //nt->Branch("Bmu1p",Bmu1p,"Bmu1p[Bsize]/F");
        //nt->Branch("Bmu2p",Bmu2p,"Bmu2p[Bsize]/F");
        //nt->Branch("Bmu1eta",Bmu1eta,"Bmu1eta[Bsize]/F");
        //nt->Branch("Bmu2eta",Bmu2eta,"Bmu2eta[Bsize]/F");
        //nt->Branch("Bmu1phi",Bmu1phi,"Bmu1phi[Bsize]/F");
        //nt->Branch("Bmu2phi",Bmu2phi,"Bmu2phi[Bsize]/F");
        
        nt->Branch("Bmu1y",Bmu1y,"Bmu1y[Bsize]/F");
        nt->Branch("Bmu2y",Bmu2y,"Bmu2y[Bsize]/F");
        
        //nt->Branch("Bmu1dzPV",Bmu1dzPV,"Bmu1dzPV[Bsize]/F");
        //nt->Branch("Bmu2dzPV",Bmu2dzPV,"Bmu2dzPV[Bsize]/F");
        //nt->Branch("Bmu1dxyPV",Bmu1dxyPV,"Bmu1dxyPV[Bsize]/F");
        //nt->Branch("Bmu2dxyPV",Bmu2dxyPV,"Bmu2dxyPV[Bsize]/F");
        //nt->Branch("Bmu1normchi2",Bmu1normchi2,"Bmu1normchi2[Bsize]/F");
        //nt->Branch("Bmu2normchi2",Bmu2normchi2,"Bmu2normchi2[Bsize]/F");
        //nt->Branch("Bmu1Chi2ndf",Bmu1Chi2ndf,"Bmu1Chi2ndf[Bsize]/F");
        //nt->Branch("Bmu2Chi2ndf",Bmu2Chi2ndf,"Bmu2Chi2ndf[Bsize]/F");
        //nt->Branch("Bmu1muqual",Bmu1muqual,"Bmu1muqual[Bsize]/I");
        //nt->Branch("Bmu2muqual",Bmu2muqual,"Bmu2muqual[Bsize]/I");
        //nt->Branch("Bmu1TrackerMuArbitrated",Bmu1TrackerMuArbitrated,"Bmu1TrackerMuArbitrated[Bsize]/O");
        //nt->Branch("Bmu2TrackerMuArbitrated",Bmu2TrackerMuArbitrated,"Bmu2TrackerMuArbitrated[Bsize]/O");
        //nt->Branch("Bmu1isTrackerMuon",Bmu1isTrackerMuon,"Bmu1isTrackerMuon[Bsize]/O");
        //nt->Branch("Bmu2isTrackerMuon",Bmu2isTrackerMuon,"Bmu2isTrackerMuon[Bsize]/O");
        //nt->Branch("Bmu1isGlobalMuon",Bmu1isGlobalMuon,"Bmu1isGlobalMuon[Bsize]/O");
        //nt->Branch("Bmu2isGlobalMuon",Bmu2isGlobalMuon,"Bmu2isGlobalMuon[Bsize]/O");
        //nt->Branch("Bmu1TMOneStationTight",Bmu1TMOneStationTight,"Bmu1TMOneStationTight[Bsize]/O");
        //nt->Branch("Bmu2TMOneStationTight",Bmu2TMOneStationTight,"Bmu2TMOneStationTight[Bsize]/O");
        //nt->Branch("Bmu1striphit",Bmu1striphit,"Bmu1striphit[Bsize]/I");
        //nt->Branch("Bmu2striphit",Bmu2striphit,"Bmu2striphit[Bsize]/I");
        //nt->Branch("Bmu1pixelhit",Bmu1pixelhit,"Bmu1pixelhit[Bsize]/I");
        //nt->Branch("Bmu2pixelhit",Bmu2pixelhit,"Bmu2pixelhit[Bsize]/I");
        //nt->Branch("Bmu1trackerhit",Bmu1trackerhit,"Bmu1trackerhit[Bsize]/I");
        //nt->Branch("Bmu2trackerhit",Bmu2trackerhit,"Bmu2trackerhit[Bsize]/I");
        //nt->Branch("Bmu1InPixelLayer",Bmu1InPixelLayer,"Bmu1InPixelLayer[Bsize]/I");
        //nt->Branch("Bmu2InPixelLayer",Bmu2InPixelLayer,"Bmu2InPixelLayer[Bsize]/I");
        //nt->Branch("Bmu1InStripLayer",Bmu1InStripLayer,"Bmu1InStripLayer[Bsize]/I");
        //nt->Branch("Bmu2InStripLayer",Bmu2InStripLayer,"Bmu2InStripLayer[Bsize]/I");
        //nt->Branch("Bmu1InTrackerLayer",Bmu1InTrackerLayer,"Bmu1InTrackerLayer[Bsize]/I");
        //nt->Branch("Bmu2InTrackerLayer",Bmu2InTrackerLayer,"Bmu2InTrackerLayer[Bsize]/I");
        //nt->Branch("Bmu1TrkQuality",Bmu1TrkQuality,"Bmu1TrkQuality[Bsize]/I");
        //nt->Branch("Bmu2TrkQuality",Bmu2TrkQuality,"Bmu2TrkQuality[Bsize]/I");
        nt->Branch("Bmu1highPurity",Bmu1highPurity,"Bmu1highPurity[Bsize]/O");
        nt->Branch("Bmu2highPurity",Bmu2highPurity,"Bmu2highPurity[Bsize]/O");
        nt->Branch("Bmu1isAcc",Bmu1isAcc,"Bmu1isAcc[Bsize]/O");
        nt->Branch("Bmu2isAcc",Bmu2isAcc,"Bmu2isAcc[Bsize]/O");
        
        nt->Branch("Bmu1SoftMuID",Bmu1SoftMuID,"Bmu1SoftMuID[Bsize]/O");
        nt->Branch("Bmu2SoftMuID",Bmu2SoftMuID,"Bmu2SoftMuID[Bsize]/O");
        nt->Branch("Bmu1HybridSoftMuID",Bmu1HybridSoftMuID,"Bmu1HybridSoftMuID[Bsize]/O");
        nt->Branch("Bmu2HybridSoftMuID",Bmu2HybridSoftMuID,"Bmu2HybridSoftMuID[Bsize]/O");
        //nt->Branch("Bmu1TrgMatchFilterE"  ,Bmu1TrgMatchFilterE,  "Bmu1TrgMatchFilterE[Bsize]/F");
        //nt->Branch("Bmu1TrgMatchFilterPt" ,Bmu1TrgMatchFilterPt, "Bmu1TrgMatchFilterPt[Bsize]/F");
        //nt->Branch("Bmu1TrgMatchFilterEta",Bmu1TrgMatchFilterEta,"Bmu1TrgMatchFilterEta[Bsize]/F");
        //nt->Branch("Bmu1TrgMatchFilterPhi",Bmu1TrgMatchFilterPhi,"Bmu1TrgMatchFilterPhi[Bsize]/F");
        nt->Branch("Bmu1isTriggered",Bmu1isTriggered,"Bmu1isTriggered[Bsize]/O");
        //nt->Branch("Bmu2TrgMatchFilterE"  ,Bmu2TrgMatchFilterE,  "Bmu2TrgMatchFilterE[Bsize]/F");
        //nt->Branch("Bmu2TrgMatchFilterPt" ,Bmu2TrgMatchFilterPt, "Bmu2TrgMatchFilterPt[Bsize]/F");
        //nt->Branch("Bmu2TrgMatchFilterEta",Bmu2TrgMatchFilterEta,"Bmu2TrgMatchFilterEta[Bsize]/F");
        //nt->Branch("Bmu2TrgMatchFilterPhi",Bmu2TrgMatchFilterPhi,"Bmu2TrgMatchFilterPhi[Bsize]/F");
        nt->Branch("Bmu2isTriggered",Bmu2isTriggered,"Bmu2isTriggered[Bsize]/O");
        nt->Branch("Bmumumass",Bmumumass,"Bmumumass[Bsize]/F");
        //nt->Branch("Bmumueta",Bmumueta,"Bmumueta[Bsize]/F");
        //nt->Branch("Bmumuphi",Bmumuphi,"Bmumuphi[Bsize]/F");
        //nt->Branch("Bmumuy",Bmumuy,"Bmumuy[Bsize]/F");
        //nt->Branch("Bmumupt",Bmumupt,"Bmumupt[Bsize]/F");
        nt->Branch("Bujmass",Bujmass,"Bujmass[Bsize]/F");
        nt->Branch("BujvProb",BujvProb,"BujvProb[Bsize]/F");
        //nt->Branch("Bujpt",Bujpt,"Bujpt[Bsize]/F");
        //nt->Branch("Bujeta",Bujeta,"Bujeta[Bsize]/F");
        //nt->Branch("Bujphi",Bujphi,"Bujphi[Bsize]/F");
        //nt->Branch("Bujy",Bujy,"Bujy[Bsize]/F");
        //nt->Branch("Bujlxy",Bujlxy,"Bujlxy[Bsize]/F");
        
        //BInfo.genInfo
        nt->Branch("Bgen",Bgen,"Bgen[Bsize]/F");
        nt->Branch("BgenIndex",BgenIndex,"BgenIndex[Bsize]/I");
        //nt->Branch("BgenpdgId",BgenpdgId,"BgenpdgId[Bsize]/I");
        //nt->Branch("Bgenmass",Bgenmass,"Bgenmass[Bsize]/F");
        //nt->Branch("Bgenpt",Bgenpt,"Bgenpt[Bsize]/F");
        //nt->Branch("BgencollisionId",BgencollisionId,"BgencollisionId[Bsize]/I");
        //nt->Branch("Bgeny",Bgeny,"Bgeny[Bsize]/F");
        //nt->Branch("Bgeneta",Bgeneta,"Bgeneta[Bsize]/F");
        //nt->Branch("Bgenphi",Bgenphi,"Bgenphi[Bsize]/F");
      }
  }
  
  int     Gsize;
  float   Gy[MAX_GEN];
  float   Geta[MAX_GEN];
  float   Gphi[MAX_GEN];
  float   Gpt[MAX_GEN];
  float   Gmass[MAX_GEN];
  int     GpdgId[MAX_GEN];
  int     GcollisionId[MAX_GEN];
  int     GisSignal[MAX_GEN];
  float   Gmu1pt[MAX_GEN];
  float   Gmu2pt[MAX_GEN];
  float   Gmu1p[MAX_GEN];
  float   Gmu2p[MAX_GEN];
  float   Gmu1eta[MAX_GEN];
  float   Gmu2eta[MAX_GEN];
  float   Gmu1phi[MAX_GEN];
  float   Gmu2phi[MAX_GEN];
  float   Gtk1pt[MAX_GEN];
  float   Gtk2pt[MAX_GEN];
  float   Gtk1eta[MAX_GEN];
  float   Gtk2eta[MAX_GEN];
  float   Gtk1phi[MAX_GEN];
  float   Gtk2phi[MAX_GEN];
  
  void buildGenBranch(TTree* nt)
  {
    nt->Branch("Gsize",&Gsize);
    nt->Branch("Gy",Gy,"Gy[Gsize]/F");
    //nt->Branch("Geta",Geta,"Geta[Gsize]/F");
    //nt->Branch("Gphi",Gphi,"Gphi[Gsize]/F");
    nt->Branch("Gpt",Gpt,"Gpt[Gsize]/F");
    nt->Branch("GpdgId",GpdgId,"GpdgId[Gsize]/I");
    nt->Branch("Gmass",Gmass,"Gmass[Gsize]/F");
    //nt->Branch("GcollisionId",GcollisionId,"GcollisionId[Gsize]/I");
    nt->Branch("GisSignal",GisSignal,"GisSignal[Gsize]/I");
    nt->Branch("Gmu1eta",Gmu1eta,"Gmu1eta[Gsize]/F");
    //nt->Branch("Gmu1phi",Gmu1phi,"Gmu1phi[Gsize]/F");
    nt->Branch("Gmu1pt",Gmu1pt,"Gmu1pt[Gsize]/F");
    //nt->Branch("Gmu1p",Gmu1p,"Gmu1p[Gsize]/F");
    nt->Branch("Gmu2eta",Gmu2eta,"Gmu2eta[Gsize]/F");
    //nt->Branch("Gmu2phi",Gmu2phi,"Gmu2phi[Gsize]/F");
    nt->Branch("Gmu2pt",Gmu2pt,"Gmu2pt[Gsize]/F");
    //nt->Branch("Gmu2p",Gmu2p,"Gmu2p[Gsize]/F");
    nt->Branch("Gtk1pt",Gtk1pt,"Gtk1pt[Gsize]/F");
    nt->Branch("Gtk1eta",Gtk1eta,"Gtk1eta[Gsize]/F");
    //nt->Branch("Gtk1phi",Gtk1phi,"Gtk1phi[Gsize]/F");
    nt->Branch("Gtk2pt",Gtk2pt,"Gtk2pt[Gsize]/F");
    nt->Branch("Gtk2eta",Gtk2eta,"Gtk2eta[Gsize]/F");
    //nt->Branch("Gtk2phi",Gtk2phi,"Gtk2phi[Gsize]/F");
  }
  
  void makeNtuple(int ifchannel[], int Btypesize[], bool REAL, EvtInfoBranches *EvtInfo, VtxInfoBranches *VtxInfo, MuonInfoBranches *MuonInfo, TrackInfoBranches *TrackInfo, BInfoBranches *BInfo, GenInfoBranches *GenInfo, TTree* nt0, TTree* nt1, TTree* nt2, TTree* nt3, TTree* nt5, TTree* nt6, TTree* nt7)
  {//{{{
    TVector3* bP        = new TVector3;
    TVector3* bVtx      = new TVector3;
    TLorentzVector* b4P = new TLorentzVector;
    fillTreeEvt(EvtInfo);

    for(int t=0; t<7; t++)
      {
        Bsize = 0;
        if(ifchannel[t]==1)
          {
            int bestindex=-1;
            for(int j=0;j<BInfo->size;j++)    // cycle through B candidates 
              {
                if(BInfo->type[j]==(t+1))
                  {
                    fillTree(bP,bVtx,b4P,j,Btypesize[t], REAL, EvtInfo, VtxInfo, MuonInfo, TrackInfo, BInfo, GenInfo, bestindex);
                    Btypesize[t]++;
                  }
              }

            if(t==0)      nt0->Fill(); // Jpsi K
            else if(t==1) nt1->Fill(); // Jpsi pi
            else if(t==2) nt2->Fill(); // Jpsi Kshort
            else if(t==3) nt3->Fill(); // Jpsi Kstar 
            else if(t==4) continue;    // NOT BEING USED now
            else if(t==5) nt5->Fill(); // Jpsi phi
            else if(t==6) nt6->Fill(); // Jpsi pi pi
          }
      }
      
    Jsize = 0;
    if(ifchannel[7]==1)
      {
        for(int j=0;j<BInfo->uj_size;j++)
          {
            fillJpsiTree(bP, bVtx, b4P, j, Btypesize[7], REAL, EvtInfo, VtxInfo, MuonInfo, TrackInfo, BInfo, GenInfo);
            Btypesize[7]++;
          }
        nt7->Fill();
      }
  }//}}}
  
  void fillGenTree(TTree* ntGen, GenInfoBranches *GenInfo, bool gskim=true)
  {//{{{
    TLorentzVector* bGen = new TLorentzVector;
    int gt=0,sigtype=0;
    int gsize=0;
    Gsize = 0;
    for(int j=0;j<GenInfo->size;j++)
      {
        if((abs(GenInfo->pdgId[j])!=BPLUS_PDGID && abs(GenInfo->pdgId[j])!=BZERO_PDGID && abs(GenInfo->pdgId[j])!=BSUBS_PDGID &&
            abs(GenInfo->pdgId[j])!=CHIC1_PDGID && abs(GenInfo->pdgId[j])!=PSI2S_PDGID && abs(GenInfo->pdgId[j])!=X_PDGID &&
            abs(GenInfo->pdgId[j])!=JPSI_PDGID) && gskim) continue;
        Gsize = gsize+1;
        GcollisionId[gsize] = GenInfo->collisionId[j];
        Gpt[gsize]    = GenInfo->pt[j];
        Geta[gsize]   = GenInfo->eta[j];
        Gphi[gsize]   = GenInfo->phi[j];
        GpdgId[gsize] = GenInfo->pdgId[j];
        Gmass[gsize]  = GenInfo->mass[j];
        bGen->SetPtEtaPhiM(Gpt[gsize],Geta[gsize],Gphi[gsize],Gmass[gsize]);
        Gy[gsize] = bGen->Rapidity();
        sigtype=0;

        for(gt=1;gt<10;gt++)
        {
          if (gt==5) continue; //skip as it is the same as gt=4(Jpsi Kstar )
          if(signalGen(gt,j,GenInfo))
          { 
            sigtype=gt;
            break;
          }
        }
        int type7flag = sigtype!=7?-1:(abs(GenInfo->pdgId[GenInfo->da2[j]])==113?1:0);
        GisSignal[gsize] = sigtype;
        Gmu1pt[gsize]  = -20;
        Gmu1eta[gsize] = -20;
        Gmu1phi[gsize] = -20;
        Gmu1p[gsize]   = -20;
        Gmu2pt[gsize]  = -20;
        Gmu2eta[gsize] = -20;
        Gmu2phi[gsize] = -20;
        Gmu2p[gsize]   = -20;
        Gtk1pt[gsize]  = -20;
        Gtk1eta[gsize] = -20;
        Gtk1phi[gsize] = -20;
        Gtk2pt[gsize]  = -20;
        Gtk2eta[gsize] = -20;
        Gtk2phi[gsize] = -20;
        if(sigtype!=0)
        {
          if(sigtype==8 || sigtype==9)
            {
              Gmu1pt[gsize] = GenInfo->pt[GenInfo->da1[j]];
              Gmu1eta[gsize] = GenInfo->eta[GenInfo->da1[j]];
              Gmu1phi[gsize] = GenInfo->phi[GenInfo->da1[j]];
              Gmu1p[gsize] = Gmu1pt[gsize]*cosh(Gmu1eta[gsize]);
              Gmu2pt[gsize] = GenInfo->pt[GenInfo->da2[j]];
              Gmu2eta[gsize] = GenInfo->eta[GenInfo->da2[j]];
              Gmu2phi[gsize] = GenInfo->phi[GenInfo->da2[j]];
              Gmu2p[gsize] = Gmu2pt[gsize]*cosh(Gmu2eta[gsize]);
            }
          else
            {
              Gmu1pt[gsize] = GenInfo->pt[GenInfo->da1[GenInfo->da1[j]]];
              Gmu1eta[gsize] = GenInfo->eta[GenInfo->da1[GenInfo->da1[j]]];
              Gmu1phi[gsize] = GenInfo->phi[GenInfo->da1[GenInfo->da1[j]]];
              Gmu1p[gsize] = Gmu1pt[gsize]*cosh(Gmu1eta[gsize]);
              Gmu2pt[gsize] = GenInfo->pt[GenInfo->da2[GenInfo->da1[j]]];
              Gmu2eta[gsize] = GenInfo->eta[GenInfo->da2[GenInfo->da1[j]]];
              Gmu2phi[gsize] = GenInfo->phi[GenInfo->da2[GenInfo->da1[j]]];
              Gmu2p[gsize] = Gmu2pt[gsize]*cosh(Gmu2eta[gsize]);
              if(sigtype==1||sigtype==2 || type7flag==0)
                {
                  Gtk1pt[gsize] = GenInfo->pt[GenInfo->da2[j]];
                  Gtk1eta[gsize] = GenInfo->eta[GenInfo->da2[j]];
                  Gtk1phi[gsize] = GenInfo->phi[GenInfo->da2[j]];
                  if(sigtype==7)
                    {
                      Gtk2pt[gsize] = GenInfo->pt[GenInfo->da3[j]];
                      Gtk2eta[gsize] = GenInfo->eta[GenInfo->da3[j]];
                      Gtk2phi[gsize] = GenInfo->phi[GenInfo->da3[j]];
                    }
                }
              else
                {
                  Gtk1pt[gsize]  = GenInfo->pt[GenInfo->da1[GenInfo->da2[j]]];
                  Gtk1eta[gsize] = GenInfo->eta[GenInfo->da1[GenInfo->da2[j]]];
                  Gtk1phi[gsize] = GenInfo->phi[GenInfo->da1[GenInfo->da2[j]]];
                  Gtk2pt[gsize]  = GenInfo->pt[GenInfo->da2[GenInfo->da2[j]]];
                  Gtk2eta[gsize] = GenInfo->eta[GenInfo->da2[GenInfo->da2[j]]];
                  Gtk2phi[gsize] = GenInfo->phi[GenInfo->da2[GenInfo->da2[j]]];
                }
            }
          gsize++;
        }
      }
    ntGen->Fill();
  }//}}}

  void fillTreeEvt(EvtInfoBranches *EvtInfo)
  {
    //Event Info
    RunNo = EvtInfo->RunNo;
    EvtNo = EvtInfo->EvtNo;
    LumiNo = EvtInfo->LumiNo;
    CentBin = EvtInfo->CentBin; //centrality

    PVx = EvtInfo->PVx;
    PVy = EvtInfo->PVy;
    PVz = EvtInfo->PVz;
    PVxE = EvtInfo->PVxE;
    PVyE = EvtInfo->PVyE;
    PVzE = EvtInfo->PVzE;
    PVnchi2 = EvtInfo->PVnchi2;
    PVchi2 = EvtInfo->PVchi2;
    BSx = EvtInfo->BSx;
    BSy = EvtInfo->BSy;
    BSz = EvtInfo->BSz;
    BSxErr = EvtInfo->BSxErr;
    BSyErr = EvtInfo->BSyErr;
    BSzErr = EvtInfo->BSzErr;
    BSdxdz = EvtInfo->BSdxdz;
    BSdydz = EvtInfo->BSdydz;
    BSdxdzErr = EvtInfo->BSdxdzErr;
    BSdydzErr = EvtInfo->BSdydzErr;
    BSWidthX = EvtInfo->BSWidthX;
    BSWidthXErr = EvtInfo->BSWidthXErr;
    BSWidthY = EvtInfo->BSWidthY;
    BSWidthYErr = EvtInfo->BSWidthYErr;
    nChargedTracks = EvtInfo->nChargedTracks;
    nSelectedChargedTracks = EvtInfo->nSelectedChargedTracks;

  }
  
  void fillTree(TVector3* bP, TVector3* bVtx, TLorentzVector* b4P, int j, int typesize, bool REAL, EvtInfoBranches *EvtInfo, VtxInfoBranches *VtxInfo, MuonInfoBranches *MuonInfo, TrackInfoBranches *TrackInfo, BInfoBranches *BInfo, GenInfoBranches *GenInfo, int &bestindex)
  {//}}}
    //Event Info
    Bsize = typesize+1;
    bVtx->SetXYZ(BInfo->vtxX[j]-EvtInfo->PVx, 
                 BInfo->vtxY[j]-EvtInfo->PVy, 
                 BInfo->vtxZ[j]*0-EvtInfo->PVz*0);

    bP->SetPtEtaPhi(BInfo->pt[j],BInfo->eta[j]*0,BInfo->phi[j]);
    Bdtheta[typesize]  = bP->Angle(*bVtx);
    Bcos_dtheta[typesize] = TMath::Cos(bP->Angle(*bVtx));

    b4P->SetPtEtaPhiM(BInfo->pt[j],BInfo->eta[j],BInfo->phi[j],BInfo->mass[j]);
    By[typesize] = b4P->Rapidity();

    Bindex[typesize] = typesize;
    Btype[typesize]  = BInfo->type[j];
    Bmass[typesize]  = BInfo->mass[j];
    Bpt[typesize]    = BInfo->pt[j];
    Beta[typesize]   = BInfo->eta[j];
    Bphi[typesize]   = BInfo->phi[j];
    BvtxX[typesize]  = BInfo->vtxX[j] - EvtInfo->PVx;
    BvtxY[typesize]  = BInfo->vtxY[j] - EvtInfo->PVy;
    Bd0[typesize]    = TMath::Sqrt((BInfo->vtxX[j]-EvtInfo->PVx)*(BInfo->vtxX[j]-EvtInfo->PVx)+(BInfo->vtxY[j]-EvtInfo->PVy)*(BInfo->vtxY[j]-EvtInfo->PVy));
    Bd0Err[typesize] = TMath::Sqrt(BInfo->vtxXErr[j]*BInfo->vtxXErr[j]+BInfo->vtxYErr[j]*BInfo->vtxYErr[j]);
    Bdxyz[typesize]  = TMath::Sqrt((BInfo->vtxX[j]-EvtInfo->PVx)*(BInfo->vtxX[j]-EvtInfo->PVx)+(BInfo->vtxY[j]-EvtInfo->PVy)*(BInfo->vtxY[j]-EvtInfo->PVy)+(BInfo->vtxZ[j]-EvtInfo->PVz)*(BInfo->vtxZ[j]-EvtInfo->PVz));
    BdxyzErr[typesize] = TMath::Sqrt(BInfo->vtxXErr[j]*BInfo->vtxXErr[j]+BInfo->vtxYErr[j]*BInfo->vtxYErr[j]+BInfo->vtxZErr[j]*BInfo->vtxZErr[j]);
    Bchi2ndf[typesize] = BInfo->vtxchi2[j]/BInfo->vtxdof[j];
    Bchi2Prob[typesize]  = TMath::Prob(BInfo->vtxchi2[j],BInfo->vtxdof[j]);

    Bmass_unfitted[typesize] = BInfo->unfitted_mass[j];
    BLxy[typesize] = ((BInfo->vtxX[j]-EvtInfo->PVx)*b4P->Px() + (BInfo->vtxY[j]-EvtInfo->PVy)*b4P->Py())/BInfo->pt[j];
    float r2lxyBS = (BInfo->vtxX[j]-EvtInfo->BSx+(BInfo->vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdxdz) * (BInfo->vtxX[j]-EvtInfo->BSx+(BInfo->vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdxdz)
     + (BInfo->vtxY[j]-EvtInfo->BSy+(BInfo->vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdydz) * (BInfo->vtxY[j]-EvtInfo->BSy+(BInfo->vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdydz);
    float xlxyBS = BInfo->vtxX[j]-EvtInfo->BSx + (BInfo->vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdxdz;
    float ylxyBS = BInfo->vtxY[j]-EvtInfo->BSy + (BInfo->vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdydz;
    BlxyBS[typesize] = TMath::Sqrt(r2lxyBS);
    BlxyBSErr[typesize] = (1./r2lxyBS) * ((xlxyBS*xlxyBS)*BInfo->vtxXErr[j] + (2*xlxyBS*ylxyBS)*BInfo->vtxYXErr[j] + (ylxyBS*ylxyBS)*BInfo->vtxYErr[j]);
    Balpha[typesize] = BInfo->alpha[j];
    BsvpvDistance[typesize] = BInfo->svpvDistance[j];
    BsvpvDisErr[typesize] = BInfo->svpvDisErr[j];
    BsvpvDistance_2D[typesize] = BInfo->svpvDistance_2D[j];
    BsvpvDisErr_2D[typesize] = BInfo->svpvDisErr_2D[j];
    Bnorm_svpvDistance[typesize] = (BInfo->svpvDistance[j])/(BInfo->svpvDisErr[j]);
    Bnorm_svpvDistance_2D[typesize] = (BInfo->svpvDistance_2D[j])/(BInfo->svpvDisErr_2D[j]);

    BMaxDoca[typesize] = BInfo->MaxDoca[j];
    
    b4P->SetPtEtaPhiM(MuonInfo->pt[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]],MuonInfo->eta[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]],MuonInfo->phi[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]],MUON_MASS);
    Bmu1pt[typesize] = MuonInfo->pt[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu1eta[typesize] = MuonInfo->eta[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu1phi[typesize] = MuonInfo->phi[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu1p[typesize] = b4P->P();
    Bmu1y[typesize] = b4P->Rapidity();
    Float_t mu1px,mu1py,mu1pz,mu1E;
    mu1px = b4P->Px();
    mu1py = b4P->Py();
    mu1pz = b4P->Pz();
    mu1E = b4P->E();

    b4P->SetPtEtaPhiM(MuonInfo->pt[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]],MuonInfo->eta[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]],MuonInfo->phi[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]],MUON_MASS);
    Bmu2pt[typesize] = MuonInfo->pt[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu2eta[typesize] = MuonInfo->eta[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu2phi[typesize] = MuonInfo->phi[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu2p[typesize] = b4P->P();
    Bmu2y[typesize] = b4P->Rapidity();
    Float_t mu2px,mu2py,mu2pz,mu2E;
    mu2px = b4P->Px();
    mu2py = b4P->Py();
    mu2pz = b4P->Pz();
    mu2E = b4P->E();

    Bmu1dzPV[typesize] = MuonInfo->dzPV[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2dzPV[typesize] = MuonInfo->dzPV[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1dxyPV[typesize] = MuonInfo->dxyPV[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2dxyPV[typesize] = MuonInfo->dxyPV[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1normchi2[typesize] = MuonInfo->normchi2[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2normchi2[typesize] = MuonInfo->normchi2[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1Chi2ndf[typesize] = MuonInfo->i_chi2[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]/MuonInfo->i_ndf[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2Chi2ndf[typesize] = MuonInfo->i_chi2[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]/MuonInfo->i_ndf[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1muqual[typesize] = MuonInfo->muqual[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2muqual[typesize] = MuonInfo->muqual[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1TrackerMuArbitrated[typesize] = MuonInfo->TrackerMuonArbitrated[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2TrackerMuArbitrated[typesize] = MuonInfo->TrackerMuonArbitrated[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1isTrackerMuon[typesize] = MuonInfo->isTrackerMuon[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2isTrackerMuon[typesize] = MuonInfo->isTrackerMuon[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1isGlobalMuon[typesize] = MuonInfo->isGlobalMuon[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2isGlobalMuon[typesize] = MuonInfo->isGlobalMuon[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1TMOneStationTight[typesize] = MuonInfo->TMOneStationTight[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2TMOneStationTight[typesize] = MuonInfo->TMOneStationTight[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1striphit[typesize] = MuonInfo->i_striphit[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu1pixelhit[typesize] = MuonInfo->i_pixelhit[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu1trackerhit[typesize] = Bmu1striphit[typesize]+Bmu1pixelhit[typesize];
    Bmu2striphit[typesize] = MuonInfo->i_striphit[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu2pixelhit[typesize] = MuonInfo->i_pixelhit[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu2trackerhit[typesize] = Bmu2striphit[typesize]+Bmu2pixelhit[typesize];
    Bmu1InPixelLayer[typesize] = MuonInfo->i_nPixelLayer[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2InPixelLayer[typesize] = MuonInfo->i_nPixelLayer[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1InStripLayer[typesize] = MuonInfo->i_nStripLayer[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2InStripLayer[typesize] = MuonInfo->i_nStripLayer[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1InTrackerLayer[typesize] = MuonInfo->i_nPixelLayer[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]] + MuonInfo->i_nStripLayer[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2InTrackerLayer[typesize] = MuonInfo->i_nPixelLayer[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]] + MuonInfo->i_nStripLayer[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1TrkQuality[typesize] = MuonInfo->innerTrackQuality[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2TrkQuality[typesize] = MuonInfo->innerTrackQuality[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1highPurity[typesize] = MuonInfo->highPurity[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2highPurity[typesize] = MuonInfo->highPurity[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1SoftMuID[typesize] = MuonInfo->SoftMuID[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2SoftMuID[typesize] = MuonInfo->SoftMuID[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
    Bmu1HybridSoftMuID[typesize] = MuonInfo->HybridSoftMuID[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
    Bmu2HybridSoftMuID[typesize] = MuonInfo->HybridSoftMuID[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];

    Bmu1isAcc[typesize] = (fabs(Bmu1eta[typesize]) < 2.4 && 
                           ((fabs(Bmu1eta[typesize]) < 1.2 && Bmu1pt[typesize] >= 3.5) ||
                            (fabs(Bmu1eta[typesize]) >= 1.2 && fabs(Bmu1eta[typesize]) < 2.1 && Bmu1pt[typesize] >= 5.47-1.89*fabs(Bmu1eta[typesize])) ||
                            (fabs(Bmu1eta[typesize]) >= 2.1 && Bmu1pt[typesize] >= 1.5)));
    Bmu2isAcc[typesize] = (fabs(Bmu2eta[typesize]) < 2.4 && 
                           ((fabs(Bmu2eta[typesize]) < 1.2 && Bmu2pt[typesize] >= 3.5) ||
                            (fabs(Bmu2eta[typesize]) >= 1.2 && fabs(Bmu2eta[typesize]) < 2.1 && Bmu2pt[typesize] >= 5.47-1.89*fabs(Bmu2eta[typesize])) ||
                            (fabs(Bmu2eta[typesize]) >= 2.1 && Bmu2pt[typesize] >= 1.5)));

    Bmu1TrgMatchFilterE[typesize]   = MuonInfo->MuTrgMatchFilterTrgObjE[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
    Bmu1TrgMatchFilterPt[typesize]  = MuonInfo->MuTrgMatchFilterTrgObjPt[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
    Bmu1TrgMatchFilterEta[typesize] = MuonInfo->MuTrgMatchFilterTrgObjEta[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
    Bmu1TrgMatchFilterPhi[typesize] = MuonInfo->MuTrgMatchFilterTrgObjPhi[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
    Bmu1isTriggered[typesize]       = MuonInfo->isTriggered[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
    Bmu2TrgMatchFilterE[typesize]   = MuonInfo->MuTrgMatchFilterTrgObjE[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
    Bmu2TrgMatchFilterPt[typesize]  = MuonInfo->MuTrgMatchFilterTrgObjPt[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
    Bmu2TrgMatchFilterEta[typesize] = MuonInfo->MuTrgMatchFilterTrgObjEta[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
    Bmu2TrgMatchFilterPhi[typesize] = MuonInfo->MuTrgMatchFilterTrgObjPhi[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
    Bmu2isTriggered[typesize]       = MuonInfo->isTriggered[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];

    b4P->SetPxPyPzE(mu1px+mu2px, mu1py+mu2py, mu1pz+mu2pz, mu1E+mu2E);
    Bmumumass[typesize] = b4P->Mag();
    Bmumueta[typesize]  = b4P->Eta();
    Bmumuphi[typesize]  = b4P->Phi();
    Bmumuy[typesize]    = b4P->Rapidity();
    Bmumupt[typesize]   = b4P->Pt();
    
    Bujmass[typesize]  = BInfo->uj_mass[BInfo->rfuj_index[j]];
    BujvProb[typesize] = TMath::Prob(BInfo->uj_vtxchi2[BInfo->rfuj_index[j]],BInfo->uj_vtxdof[BInfo->rfuj_index[j]]);
    Bujpt[typesize]    = BInfo->uj_pt[BInfo->rfuj_index[j]];
    Bujeta[typesize]   = BInfo->uj_eta[BInfo->rfuj_index[j]];
    Bujphi[typesize]   = BInfo->uj_phi[BInfo->rfuj_index[j]];
    b4P->SetPtEtaPhiM(Bujpt[typesize], Bujeta[typesize], Bujphi[typesize], Bujmass[typesize]);
    Bujy[typesize] = b4P->Rapidity();
    Bujlxy[typesize] = ((BInfo->uj_vtxX[BInfo->rfuj_index[j]]-EvtInfo->PVx)*b4P->Px() + (BInfo->uj_vtxY[BInfo->rfuj_index[j]]-EvtInfo->PVy)*b4P->Py())/Bujpt[typesize];

    Btrk1Idx = int(BInfo->rftk1_index[j]);
    Btrk2Idx = int(BInfo->rftk2_index[j]);

    //Track 1 
    Btrk1Pt[typesize]          = TrackInfo->pt[Btrk1Idx];
    Btrk1Eta[typesize]         = TrackInfo->eta[Btrk1Idx];
    Btrk1Phi[typesize]         = TrackInfo->phi[Btrk1Idx];
    Btrk1PtErr[typesize]       = TrackInfo->ptErr[Btrk1Idx];
    Btrk1EtaErr[typesize]      = TrackInfo->etaErr[Btrk1Idx];
    Btrk1PhiErr[typesize]      = TrackInfo->phiErr[Btrk1Idx];
    Btrk1Dz[typesize]          = TrackInfo->dz[Btrk1Idx];
    Btrk1DzError[typesize]     = TrackInfo->dzerror[Btrk1Idx];
    Bnorm_trk1Dz[typesize]     = (Btrk1Dz[typesize]) / (Btrk1DzError[typesize]);
    Btrk1Dxy[typesize]         = TrackInfo->dxy[Btrk1Idx];
    Btrk1DxyError[typesize]    = TrackInfo->dxyerror[Btrk1Idx];
    Bnorm_trk1Dxy[typesize]    = (Btrk1Dxy[typesize]) / (Btrk1DxyError[typesize]);
    Btrk1PixelHit[typesize]    = TrackInfo->pixelhit[Btrk1Idx];
    Btrk1StripHit[typesize]    = TrackInfo->striphit[Btrk1Idx];
    Btrk1nPixelLayer[typesize] = TrackInfo->nPixelLayer[Btrk1Idx];
    Btrk1nStripLayer[typesize] = TrackInfo->nStripLayer[Btrk1Idx];
    Btrk1Chi2ndf[typesize]     = TrackInfo->chi2[Btrk1Idx]/TrackInfo->ndf[Btrk1Idx];
    Btrk1MVAVal[typesize]      = TrackInfo->trkMVAVal[Btrk1Idx];
    Btrk1Algo[typesize]        = TrackInfo->trkAlgo[Btrk1Idx];
    Btrk1originalAlgo[typesize] = TrackInfo->originalTrkAlgo[Btrk1Idx];
    Btrk1highPurity[typesize]   = TrackInfo->highPurity[Btrk1Idx];
    Btrk1Quality[typesize]      = TrackInfo->trackQuality[Btrk1Idx];
    Btrk1dR[typesize] = TMath::Sqrt(pow(TMath::ACos(TMath::Cos(Bujphi[typesize]-Btrk1Phi[typesize])),2) + pow(Bujeta[typesize]-Btrk1Eta[typesize],2));
    
    if(BInfo->type[j]==1 || BInfo->type[j]==2)   // Jpsi K    ||OR||    Jpsi pi        (so no second track!)
    {
      Btrk2Pt[typesize]           = -20;
      Btrk2Eta[typesize]          = -20;
      Btrk2Phi[typesize]          = -20;
      Btrk2PtErr[typesize]        = -20;
      Btrk2EtaErr[typesize]       = -20;
      Btrk2PhiErr[typesize]       = -20;
      Btrk2Y[typesize]            = -20;
      Btrk2Dz[typesize]           = -20;
      Btrk2DzError[typesize]      = -20;
      Bnorm_trk2Dz[typesize]      = -20;
      Btrk2Dxy[typesize]          = -20;
      Btrk2DxyError[typesize]     = -20;
      Bnorm_trk2Dxy[typesize]     = -20;
      Btrk2PixelHit[typesize]     = -20;
      Btrk2StripHit[typesize]     = -20;
      Btrk2nPixelLayer[typesize]  = -20;
      Btrk2nStripLayer[typesize]  = -20;
      Btrk2Chi2ndf[typesize]      = -20;
      Btrk2MVAVal[typesize]       = -20;
      Btrk2Algo[typesize]         = -20;
      Btrk2originalAlgo[typesize] = -20;
      Btrk2highPurity[typesize]   = -20;
      Btrk2Quality[typesize]      = -20;
      Btrk2dR[typesize]           = -20;

      Btktkmass[typesize]         = -20;
      BtktkvProb[typesize]        = -20;
      Btktkpt[typesize]           = -20;
      Btktketa[typesize]          = -20;
      Btktkphi[typesize]          = -20;
      Btktky[typesize]            = -20;
      Bdoubletmass[typesize]      = -20;
      Bdoubletpt[typesize]        = -20;
      Bdoubleteta[typesize]       = -20;
      Bdoubletphi[typesize]       = -20;
      Bdoublety[typesize]         = -20;
      BtrkPtimb[typesize]         = -20;
      BQvalue[typesize]           = -20;
      BQvalueuj[typesize]         = -20;
    }
    else  //Specify the 2nd Track 
    {
      Btrk2Pt[typesize]           = TrackInfo->pt[Btrk2Idx];
      Btrk2Eta[typesize]          = TrackInfo->eta[Btrk2Idx];
      Btrk2Phi[typesize]          = TrackInfo->phi[Btrk2Idx];
      Btrk2PtErr[typesize]        = TrackInfo->ptErr[Btrk2Idx];
      Btrk2EtaErr[typesize]       = TrackInfo->etaErr[Btrk2Idx];
      Btrk2PhiErr[typesize]       = TrackInfo->phiErr[Btrk2Idx];
      Btrk2Dz[typesize]           = TrackInfo->dz[Btrk2Idx];
      Btrk2DzError[typesize]      = TrackInfo->dzerror[Btrk2Idx];
      Btrk2Dxy[typesize]          = TrackInfo->dxy[Btrk2Idx];
      Btrk2DxyError[typesize]     = TrackInfo->dxyerror[Btrk2Idx];
      Btrk2Dz1[typesize]          = TrackInfo->dz1[Btrk2Idx];
      Btrk2DzError1[typesize]     = TrackInfo->dzerror1[Btrk2Idx];
      Btrk2Dxy1[typesize]         = TrackInfo->dxy1[Btrk2Idx];
      Btrk2DxyError1[typesize]    = TrackInfo->dxyerror1[Btrk2Idx];
      Btrk2PixelHit[typesize]     = TrackInfo->pixelhit[Btrk2Idx];
      Btrk2StripHit[typesize]     = TrackInfo->striphit[Btrk2Idx];
      Btrk2nPixelLayer[typesize]  = TrackInfo->nPixelLayer[Btrk2Idx];
      Btrk2nStripLayer[typesize]  = TrackInfo->nStripLayer[Btrk2Idx];
      Btrk2Chi2ndf[typesize]      = TrackInfo->chi2[Btrk2Idx]/TrackInfo->ndf[Btrk2Idx];
      Btrk2MVAVal[typesize]       = TrackInfo->trkMVAVal[Btrk2Idx];
      Btrk2Algo[typesize]         = TrackInfo->trkAlgo[Btrk2Idx];
      Btrk2originalAlgo[typesize] = TrackInfo->originalTrkAlgo[Btrk2Idx];
      Btrk2highPurity[typesize]   = TrackInfo->highPurity[Btrk2Idx];
      Btrk2Quality[typesize]      = TrackInfo->trackQuality[Btrk2Idx];
      Bnorm_trk2Dxy[typesize] = (Btrk2Dxy[typesize]) / (Btrk2DxyError[typesize]) ;
      Bnorm_trk2Dz[typesize]  = (Btrk2Dz[typesize])  / (Btrk2DzError[typesize])  ;
      Btrk2dR[typesize] = TMath::Sqrt(pow(TMath::ACos(TMath::Cos(Bujphi[typesize]-Btrk2Phi[typesize])),2) + pow(Bujeta[typesize]-Btrk2Eta[typesize],2));
    }
    float tk1px,tk1py,tk1pz,tk1E;
    float tk2px,tk2py,tk2pz,tk2E;
  
    // 2 Track channels only ELSE -> -20
    if (Btrk1Pt[typesize] > 0 && Btrk2Pt[typesize] > 0) {

      BtrkPtimb[typesize]  = abs(Btrk1Pt[typesize] - Btrk2Pt[typesize]) / abs(Btrk1Pt[typesize]+Btrk2Pt[typesize]);
      BtktkvProb[typesize] = TMath::Prob(BInfo->tktk_vtxchi2[j],BInfo->tktk_vtxdof[j]);

      b4P->SetPtEtaPhiM(TrackInfo->pt[Btrk1Idx],TrackInfo->eta[Btrk1Idx],TrackInfo->phi[Btrk1Idx],BInfo->rftk1_mass[j]);
      Btrk1Y[typesize] = b4P->Rapidity();
      tk1px = b4P->Px();
      tk1py = b4P->Py();
      tk1pz = b4P->Pz();
      tk1E  = b4P->E();
      b4P->SetPtEtaPhiM(TrackInfo->pt[Btrk2Idx],TrackInfo->eta[Btrk2Idx],TrackInfo->phi[Btrk2Idx],BInfo->rftk2_mass[j]);
      Btrk2Y[typesize]  = b4P->Rapidity();
      tk2px = b4P->Px();
      tk2py = b4P->Py();
      tk2pz = b4P->Pz();
      tk2E  = b4P->E();
      b4P->SetPxPyPzE(tk1px+tk2px, tk1py+tk2py, tk1pz+tk2pz, tk1E+tk2E);
      Btktkmass[typesize] = b4P->Mag();
      Btktketa[typesize]  = b4P->Eta();
      Btktkphi[typesize]  = b4P->Phi();
      Btktky[typesize]    = b4P->Rapidity();
      Btktkpt[typesize]   = b4P->Pt();
      b4P->SetPtEtaPhiM(BInfo->tktk_pt[j],BInfo->tktk_eta[j], BInfo->tktk_phi[j],BInfo->tktk_mass[j]);
      Bdoublety[typesize] = b4P->Rapidity();
      Bdoubletmass[typesize] = BInfo->tktk_mass[j];
      Bdoubletpt[typesize]   = BInfo->tktk_pt[j];
      Bdoubleteta[typesize]  = BInfo->tktk_eta[j];
      Bdoubletphi[typesize]  = BInfo->tktk_phi[j];

      BQvalue[typesize]   = (Bmass[typesize]-3.096916-Btktkmass[typesize]);
      BQvalueuj[typesize] = (Bmass[typesize]-Bujmass[typesize]-Btktkmass[typesize]);
    }
    // 2 Track channels only ELSE -> -20

    // LEADING pT track
    bool istrk1H = Btrk1Pt[typesize]>Btrk2Pt[typesize];
    BtrkLH[typesize] = istrk1H?1:2;
    BtrkHPt[typesize] = istrk1H?Btrk1Pt[typesize]:Btrk2Pt[typesize];
    BtrkLPt[typesize] = istrk1H?Btrk2Pt[typesize]:Btrk1Pt[typesize];
    BtrkHPhi[typesize] = istrk1H?Btrk1Phi[typesize]:Btrk2Phi[typesize];
    BtrkLPhi[typesize] = istrk1H?Btrk2Phi[typesize]:Btrk1Phi[typesize];
    BtrkHEta[typesize] = istrk1H?Btrk1Eta[typesize]:Btrk2Eta[typesize];
    BtrkLEta[typesize] = istrk1H?Btrk2Eta[typesize]:Btrk1Eta[typesize];
    BtrkHDxy1[typesize] = istrk1H?Btrk1Dxy1[typesize]:Btrk2Dxy1[typesize];
    BtrkLDxy1[typesize] = istrk1H?Btrk2Dxy1[typesize]:Btrk1Dxy1[typesize];
    BtrkHDxyError1[typesize] = istrk1H?Btrk1DxyError1[typesize]:Btrk2DxyError1[typesize];
    BtrkLDxyError1[typesize] = istrk1H?Btrk2DxyError1[typesize]:Btrk1DxyError1[typesize];
    BtrkHDz1[typesize] = istrk1H?Btrk1Dz1[typesize]:Btrk2Dz1[typesize];
    BtrkLDz1[typesize] = istrk1H?Btrk2Dz1[typesize]:Btrk1Dz1[typesize];
    BtrkHDzError1[typesize] = istrk1H?Btrk1DzError1[typesize]:Btrk2DzError1[typesize];
    BtrkLDzError1[typesize] = istrk1H?Btrk2DzError1[typesize]:Btrk1DzError1[typesize];

    //gen info judgement
    if(!REAL)
      {
        Bgen[typesize]      = 0;
        BgenIndex[typesize] = -20;
        BgenpdgId[typesize] = 0;
        Bgenmass[typesize]  = -20;
        Bgenpt[typesize]    = -20;
        BgencollisionId[typesize] = -20;
        Bgeneta[typesize] = -20;
        Bgenphi[typesize] = -20;
        Bgeny[typesize] = -1;
        int mGenIdxTk1 = -1;
        int mGenIdxTk2 = -1;
        int bGenIdxTk1 = -1;
        int bGenIdxTk2 = -1;
        int bGenIdxMu1 = -1;
        int bGenIdxMu2 = -1;
        int flagB0WT = 0;
        // int ujGenIdxMu1=-1;
        // int ujGenIdxMu2=-1;

        std::vector<float> BId;
        float MId,tk1Id,tk2Id;
        //tk1:positive, tk2:negtive
        if(BInfo->type[j]==1)
          {
            BId.push_back(521);//B+-
            MId = -20;
            tk1Id = 321;//K+-
            tk2Id = -20;
          }
        if(BInfo->type[j]==2)
          {
            BId.push_back(521);//B+-
            MId = -20;
            tk1Id = 211;//pi+-
            tk2Id = -20;
          }
        if(BInfo->type[j]==3)
          {
            BId.push_back(511);//B0
            MId = 310;//Ks
            tk1Id = 211;//pi+
            tk2Id = 211;//pi-
          }
        if(BInfo->type[j]==4)
          {
            BId.push_back(511);//B0
            MId = 313;//K*0
            if ( float(BInfo->rftk2_mass[j]) == float(PION_MASS)) {
              tk1Id = KAON_PDGID; 
              tk2Id = PION_PDGID; 
            } 
            else if ( float(BInfo->rftk2_mass[j]) == float(KAON_MASS)) {
              tk1Id = PION_PDGID; 
              tk2Id = KAON_PDGID; 
            }
          }
        if(BInfo->type[j]==6)
          {
            BId.push_back(531);//Bs
            MId = 333;  //phi
            tk1Id = 321;//K+
            tk2Id = 321;//K-
          }
        if(BInfo->type[j]==7)
          {
            BId.push_back(20443);   //chic1
            BId.push_back(100443);  //psi'
            BId.push_back(9920443); //np X3872
            MId = 113;   //rho
            tk1Id = 211; //pi+
            tk2Id = 211; //pi-
          }

        int twoTks;
        if(BInfo->type[j]==1 || BInfo->type[j]==2) twoTks=0;
        else twoTks=1;
        
        //tk1
        if(TrackInfo->geninfo_index[Btrk1Idx]>-1)
        {
          int level =0;
          if(abs(GenInfo->pdgId[TrackInfo->geninfo_index[Btrk1Idx]])==tk1Id)
          {
            level = 1;
            if(GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]>-1)
            {
              if(!twoTks)//one trk channel
              {
                mGenIdxTk1=0;
                if(isBId(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]]), BId))
                {
                  level = 3;
                  bGenIdxTk1=GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]];
                }		  
              }
              else//two trk channel
              {
                if(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]])==MId) // w/ resonance
                {
                  level = 2;
                  if(GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]]>-1)
                  {
                    if(isBId(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]]]), BId))
                    {
                      level = 3;
                      bGenIdxTk1=GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]];
                    }
                  }
                  mGenIdxTk1=GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]];
                }
                else if(BInfo->type[j]==7) // w/o resonance
                {
                  mGenIdxTk1=0;
                  if(isBId(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]]), BId))
                  {
                    level = 3;
                    bGenIdxTk1=GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]];
                  }
                }
              }
            }
          }
          Bgen[typesize]=level;
        }
              
        //tk2
        if(!twoTks)//one trk channel
          {
            Bgen[typesize]+=30;
            mGenIdxTk2=0;
            bGenIdxTk2=0;
          }
        else//two trk channel
        {
          if(TrackInfo->geninfo_index[Btrk2Idx]>-1)
          {
            int level =0;
            if(abs(GenInfo->pdgId[TrackInfo->geninfo_index[Btrk2Idx]])==tk2Id)
            {
              level = 1;
              if(GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]>-1)
              {
                if(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]])==MId) // w/ resonance
                {
                  level = 2;
                  if(GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]]>-1)
                  {
                    if(isBId(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]]]), BId))
                    {
                      level = 3;
                      bGenIdxTk2 = GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]];
                    }
                  }
                  mGenIdxTk2 = GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]];
                }
                else if(BInfo->type[j]==7) // w/o resonance
                {
                  mGenIdxTk2 = 0;
                  if(isBId(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]]), BId))
                  {
                    level = 3;
                    bGenIdxTk2 = GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]];
                  }
                }
              }
            }
            Bgen[typesize]+=(level*10);
          }
        }

        //mu1
        if(MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]>-1)
          {
            int level = 0;
            if(abs(GenInfo->pdgId[MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]])==13)
              {
                level=1;
                int murad = 0;
                int muidx = MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
                while(GenInfo->mo1[muidx]>-1)
                  {
                    if(abs(GenInfo->pdgId[GenInfo->mo1[muidx]])!=13) break;
                    muidx = GenInfo->mo1[muidx];
                    murad++;
                  }
                if(GenInfo->mo1[muidx]>-1)
                  {
                    if(GenInfo->pdgId[GenInfo->mo1[muidx]]==443)
                      {
                        // ujGenIdxMu1 = GenInfo->mo1[muidx];
                        level=2;
                        if(GenInfo->mo1[GenInfo->mo1[muidx]]>-1)
                          {
                            if(isBId(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[muidx]]]), BId))
                              {
                                level = 3;
                                bGenIdxMu1=GenInfo->mo1[GenInfo->mo1[muidx]];
                                flagB0WT ++; // =1
                                if(murad) { level = 4; }
                              }
                          }
                      }
                  }
              }
            Bgen[typesize]+=(level*100);
          }
        
        //mu2
        if(MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]>-1)
        {
          int level = 0;
          if(abs(GenInfo->pdgId[MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]])==13)
            {
              level=1;
              int murad = 0;
              int muidx = MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
              while(GenInfo->mo1[muidx]>-1)
                {
                  if(abs(GenInfo->pdgId[GenInfo->mo1[muidx]])!=13) break;
                  muidx = GenInfo->mo1[muidx];
                  murad++;
                }
              if(GenInfo->mo1[muidx]>-1)
                {
                  if(GenInfo->pdgId[GenInfo->mo1[muidx]]==443)
                    {
                      // ujGenIdxMu2 = GenInfo->mo1[muidx];
                      level=2;
                      if(GenInfo->mo1[GenInfo->mo1[muidx]]>-1)
                        {
                          if(isBId(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[muidx]]]), BId))
                            {
                              level = 3;
                              bGenIdxMu2=GenInfo->mo1[GenInfo->mo1[muidx]];
                              flagB0WT ++; // =2
                              if(murad) { level = 4; }
                            }
                        }
                    } 
                }
            }
          Bgen[typesize]+=(level*1000);
        }

        int level=0;
        if(mGenIdxTk1!=-1 && mGenIdxTk2!=-1)
          {
            if(!twoTks) level=1;
            else
              {
                if(mGenIdxTk1==mGenIdxTk2) level=1;
              }
          }
        if(bGenIdxMu1!=-1 && bGenIdxMu1==bGenIdxMu2 && bGenIdxMu1==bGenIdxTk1)
          {
            if(!twoTks)
              {
                level=2;
                BgenIndex[typesize] = bGenIdxMu1;
              }
            else if(bGenIdxMu1==bGenIdxTk2)
              {
                level=2;
                BgenIndex[typesize] = bGenIdxMu1;
              }
          }
        
        Bgen[typesize]+=(level*10000);

        // WT WT WT WT Kstart #############################################################################
        if(BInfo->type[j]==4)
        {
          //tk1
          if(TrackInfo->geninfo_index[Btrk1Idx]>-1)
          {
            if(abs(GenInfo->pdgId[TrackInfo->geninfo_index[Btrk1Idx]])==tk2Id)
            {
              if(GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]>-1)
              {
                if(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]]) == MId)
                {
                  if(GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]]>-1)
                  {
                    if(isBId(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]]]), BId))
                    {
                      flagB0WT ++;//=2
                      bGenIdxTk1=GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]]];
                    }
                  }
                  mGenIdxTk1=GenInfo->mo1[TrackInfo->geninfo_index[Btrk1Idx]];
                }
              }
            }
          }
          //tk2
          if(TrackInfo->geninfo_index[Btrk2Idx]>-1)
          {
            if(abs(GenInfo->pdgId[TrackInfo->geninfo_index[Btrk2Idx]])==tk1Id)
            {
              if(GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]>-1)
              {
                if(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]])==MId)
                {
                  if(GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]]>-1)
                  {
                    if(isBId(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]]]), BId))
                    {
                      flagB0WT ++;//=3
                      bGenIdxTk2 = GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]]];
                    }
                  }
                  mGenIdxTk2 = GenInfo->mo1[TrackInfo->geninfo_index[Btrk2Idx]];
                }
              }
            }
          }
          if(flagB0WT==4)
          {
            if((bGenIdxMu1!=-1) && (bGenIdxMu1==bGenIdxMu2) && (bGenIdxMu1==bGenIdxTk1) && (bGenIdxMu1==bGenIdxTk2))
            {
              Bgen[typesize]=41000;
              BgenIndex[typesize] = bGenIdxMu1;
            }
          }
        }
        //kstar End############################################################################

        int tgenIndex= BgenIndex[typesize];
        
        if(Bgen[typesize]==41000 || Bgen[typesize]==23333 || Bgen[typesize]==24433 || Bgen[typesize]==24333 || Bgen[typesize]==23433 )
          {
            std::cout << GenInfo->pdgId[tgenIndex] << " ==> Signal found ("<<  Bgen[typesize] <<") with Bgenmass= " << GenInfo->mass[tgenIndex] << std::endl;

            Bgenpt[typesize] = GenInfo->pt[tgenIndex];
            BgenpdgId[typesize] = GenInfo->pdgId[tgenIndex];
            Bgenmass[typesize]  = GenInfo->mass[tgenIndex];
            BgencollisionId[typesize] = GenInfo->collisionId[tgenIndex];
            Bgeneta[typesize] = GenInfo->eta[tgenIndex];
            Bgenphi[typesize] = GenInfo->phi[tgenIndex];
            b4P->SetXYZM(GenInfo->pt[tgenIndex]*cos(GenInfo->phi[tgenIndex]),
                         GenInfo->pt[tgenIndex]*sin(GenInfo->phi[tgenIndex]),
                         GenInfo->pt[tgenIndex]*sinh(GenInfo->eta[tgenIndex]),
                         GenInfo->mass[tgenIndex]);
            Bgeny[typesize] = b4P->Rapidity();
          }
      }
  }//}}}

  void fillJpsiTree(TVector3* bP, TVector3* bVtx, TLorentzVector* b4P, int j, int typesize, bool REAL, EvtInfoBranches *EvtInfo, VtxInfoBranches *VtxInfo, MuonInfoBranches *MuonInfo, TrackInfoBranches *TrackInfo, BInfoBranches *BInfo, GenInfoBranches *GenInfo)
  {
    Jsize = typesize+1;

    bVtx->SetXYZ(BInfo->uj_vtxX[j]-EvtInfo->PVx,
                 BInfo->uj_vtxY[j]-EvtInfo->PVy,
                 BInfo->uj_vtxZ[j]*0-EvtInfo->PVz*0);

    bP->SetPtEtaPhi(BInfo->uj_pt[j],BInfo->uj_eta[j]*0,BInfo->uj_phi[j]);
    Jdtheta[typesize] = bP->Angle(*bVtx);

    b4P->SetPtEtaPhiM(BInfo->uj_pt[j],BInfo->uj_eta[j],BInfo->uj_phi[j],BInfo->uj_mass[j]);
    
    Jindex[typesize] = typesize;
    Jmass[typesize] = BInfo->uj_mass[j];
    Jpt[typesize] = BInfo->uj_pt[j];
    Jeta[typesize] = BInfo->uj_eta[j];
    Jphi[typesize] = BInfo->uj_phi[j];
    Jy[typesize] = b4P->Rapidity();
    JvtxX[typesize] = BInfo->uj_vtxX[j] - EvtInfo->PVx;
    JvtxY[typesize] = BInfo->uj_vtxY[j] - EvtInfo->PVy;
    Jd0[typesize] = TMath::Sqrt((BInfo->uj_vtxX[j]-EvtInfo->PVx)*(BInfo->uj_vtxX[j]-EvtInfo->PVx)+(BInfo->uj_vtxY[j]-EvtInfo->PVy)*(BInfo->uj_vtxY[j]-EvtInfo->PVy));
    Jdxyz[typesize] = TMath::Sqrt((BInfo->uj_vtxX[j]-EvtInfo->PVx)*(BInfo->uj_vtxX[j]-EvtInfo->PVx)+(BInfo->uj_vtxY[j]-EvtInfo->PVy)*(BInfo->uj_vtxY[j]-EvtInfo->PVy)+(BInfo->uj_vtxZ[j]-EvtInfo->PVz)*(BInfo->uj_vtxZ[j]-EvtInfo->PVz));
    Jchi2ndf[typesize] = BInfo->uj_vtxchi2[j]/BInfo->uj_vtxdof[j];
    Jchi2cl[typesize] = TMath::Prob(BInfo->uj_vtxchi2[j],BInfo->uj_vtxdof[j]);
    Jlxy[typesize] = ((BInfo->uj_vtxX[j]-EvtInfo->PVx)*b4P->Px() + (BInfo->uj_vtxY[j]-EvtInfo->PVy)*b4P->Py())/BInfo->uj_pt[j];
    float r2lxyBS = (BInfo->uj_vtxX[j]-EvtInfo->BSx+(BInfo->uj_vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdxdz) * (BInfo->uj_vtxX[j]-EvtInfo->BSx+(BInfo->uj_vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdxdz)
      + (BInfo->uj_vtxY[j]-EvtInfo->BSy+(BInfo->uj_vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdydz) * (BInfo->uj_vtxY[j]-EvtInfo->BSy+(BInfo->uj_vtxZ[j]-EvtInfo->BSz)*EvtInfo->BSdydz);
    JlxyBS[typesize] = TMath::Sqrt(r2lxyBS);
    
    b4P->SetPtEtaPhiM(MuonInfo->pt[BInfo->uj_rfmu1_index[j]],MuonInfo->eta[BInfo->uj_rfmu1_index[j]],MuonInfo->phi[BInfo->uj_rfmu1_index[j]],MUON_MASS);
    Jmu1pt[typesize] = MuonInfo->pt[BInfo->uj_rfmu1_index[j]];
    Jmu1eta[typesize] = MuonInfo->eta[BInfo->uj_rfmu1_index[j]];
    Jmu1phi[typesize] = MuonInfo->phi[BInfo->uj_rfmu1_index[j]];
    Jmu1p[typesize] = b4P->P();
    Jmu1y[typesize] = b4P->Rapidity();
    Float_t mu1px,mu1py,mu1pz,mu1E;
    mu1px = b4P->Px();
    mu1py = b4P->Py();
    mu1pz = b4P->Pz();
    mu1E = b4P->E();
    
    b4P->SetPtEtaPhiM(MuonInfo->pt[BInfo->uj_rfmu2_index[j]],MuonInfo->eta[BInfo->uj_rfmu2_index[j]],MuonInfo->phi[BInfo->uj_rfmu2_index[j]],MUON_MASS);
    Jmu2pt[typesize] = MuonInfo->pt[BInfo->uj_rfmu2_index[j]];
    Jmu2eta[typesize] = MuonInfo->eta[BInfo->uj_rfmu2_index[j]];
    Jmu2phi[typesize] = MuonInfo->phi[BInfo->uj_rfmu2_index[j]];
    Jmu2p[typesize] = b4P->P();
    Jmu2y[typesize] = b4P->Rapidity();
    Float_t mu2px,mu2py,mu2pz,mu2E;
    mu2px = b4P->Px();
    mu2py = b4P->Py();
    mu2pz = b4P->Pz();
    mu2E = b4P->E();

    Jmu1dzPV[typesize] = MuonInfo->dzPV[BInfo->uj_rfmu1_index[j]];
    Jmu2dzPV[typesize] = MuonInfo->dzPV[BInfo->uj_rfmu2_index[j]];
    Jmu1dxyPV[typesize] = MuonInfo->dxyPV[BInfo->uj_rfmu1_index[j]];
    Jmu2dxyPV[typesize] = MuonInfo->dxyPV[BInfo->uj_rfmu2_index[j]];
    Jmu1normchi2[typesize] = MuonInfo->normchi2[BInfo->uj_rfmu1_index[j]];
    Jmu2normchi2[typesize] = MuonInfo->normchi2[BInfo->uj_rfmu2_index[j]];
    Jmu1Chi2ndf[typesize] = MuonInfo->i_chi2[BInfo->uj_rfmu1_index[j]]/MuonInfo->i_ndf[BInfo->uj_rfmu1_index[j]];
    Jmu2Chi2ndf[typesize] = MuonInfo->i_chi2[BInfo->uj_rfmu2_index[j]]/MuonInfo->i_ndf[BInfo->uj_rfmu2_index[j]];
    Jmu1muqual[typesize] = MuonInfo->muqual[BInfo->uj_rfmu1_index[j]];
    Jmu2muqual[typesize] = MuonInfo->muqual[BInfo->uj_rfmu2_index[j]];
    Jmu1TrackerMuArbitrated[typesize] = MuonInfo->TrackerMuonArbitrated[BInfo->uj_rfmu1_index[j]];
    Jmu2TrackerMuArbitrated[typesize] = MuonInfo->TrackerMuonArbitrated[BInfo->uj_rfmu2_index[j]];
    Jmu1isTrackerMuon[typesize] = MuonInfo->isTrackerMuon[BInfo->uj_rfmu1_index[j]];
    Jmu2isTrackerMuon[typesize] = MuonInfo->isTrackerMuon[BInfo->uj_rfmu2_index[j]];
    Jmu1isGlobalMuon[typesize] = MuonInfo->isGlobalMuon[BInfo->uj_rfmu1_index[j]];
    Jmu2isGlobalMuon[typesize] = MuonInfo->isGlobalMuon[BInfo->uj_rfmu2_index[j]];
    Jmu1TMOneStationTight[typesize] = MuonInfo->TMOneStationTight[BInfo->uj_rfmu1_index[j]];
    Jmu2TMOneStationTight[typesize] = MuonInfo->TMOneStationTight[BInfo->uj_rfmu2_index[j]];
    Jmu1striphit[typesize] = MuonInfo->i_striphit[BInfo->uj_rfmu1_index[j]];
    Jmu1pixelhit[typesize] = MuonInfo->i_pixelhit[BInfo->uj_rfmu1_index[j]];
    Jmu1trackerhit[typesize] = Jmu1striphit[typesize]+Bmu1pixelhit[typesize];
    Jmu2striphit[typesize] = MuonInfo->i_striphit[BInfo->uj_rfmu2_index[j]];
    Jmu2pixelhit[typesize] = MuonInfo->i_pixelhit[BInfo->uj_rfmu2_index[j]];
    Jmu2trackerhit[typesize] = Bmu2striphit[typesize]+Bmu2pixelhit[typesize];
    Jmu1InPixelLayer[typesize] = MuonInfo->i_nPixelLayer[BInfo->uj_rfmu1_index[j]];
    Jmu2InPixelLayer[typesize] = MuonInfo->i_nPixelLayer[BInfo->uj_rfmu2_index[j]];
    Jmu1InStripLayer[typesize] = MuonInfo->i_nStripLayer[BInfo->uj_rfmu1_index[j]];
    Jmu2InStripLayer[typesize] = MuonInfo->i_nStripLayer[BInfo->uj_rfmu2_index[j]];
    Jmu1InTrackerLayer[typesize] = MuonInfo->i_nPixelLayer[BInfo->uj_rfmu1_index[j]] + MuonInfo->i_nStripLayer[BInfo->uj_rfmu1_index[j]];
    Jmu2InTrackerLayer[typesize] = MuonInfo->i_nPixelLayer[BInfo->uj_rfmu2_index[j]] + MuonInfo->i_nStripLayer[BInfo->uj_rfmu2_index[j]];
    Jmu1TrkQuality[typesize] = MuonInfo->innerTrackQuality[BInfo->uj_rfmu1_index[j]];
    Jmu2TrkQuality[typesize] = MuonInfo->innerTrackQuality[BInfo->uj_rfmu2_index[j]];
    Jmu1highPurity[typesize] = MuonInfo->highPurity[BInfo->uj_rfmu1_index[j]];
    Jmu2highPurity[typesize] = MuonInfo->highPurity[BInfo->uj_rfmu2_index[j]];
    Jmu1SoftMuID[typesize] = MuonInfo->SoftMuID[BInfo->uj_rfmu1_index[j]];
    Jmu2SoftMuID[typesize] = MuonInfo->SoftMuID[BInfo->uj_rfmu2_index[j]];
    Jmu1isAcc[typesize] = (fabs(Jmu1eta[typesize]) < 2.4 &&
                           ((fabs(Jmu1eta[typesize]) < 1.2 && Jmu1pt[typesize] >= 3.5) ||
                            (fabs(Jmu1eta[typesize]) >= 1.2 && fabs(Jmu1eta[typesize]) < 2.1 && Jmu1pt[typesize] >= 5.47-1.89*fabs(Jmu1eta[typesize])) ||
                            (fabs(Jmu1eta[typesize]) >= 2.1 && Jmu1pt[typesize] >= 1.5)));
    Jmu2isAcc[typesize] = (fabs(Jmu2eta[typesize]) < 2.4 &&
                           ((fabs(Jmu2eta[typesize]) < 1.2 && Jmu2pt[typesize] >= 3.5) ||
                            (fabs(Jmu2eta[typesize]) >= 1.2 && fabs(Jmu2eta[typesize]) < 2.1 && Jmu2pt[typesize] >= 5.47-1.89*fabs(Jmu2eta[typesize])) ||
                            (fabs(Jmu2eta[typesize]) >= 2.1 && Jmu2pt[typesize] >= 1.5)));

    Jmu1TrgMatchFilterE[typesize] = MuonInfo->MuTrgMatchFilterTrgObjE[BInfo->uj_rfmu1_index[j]*MuonInfo->MuTrgMatchFilterSize+0];
    Jmu1TrgMatchFilterPt[typesize] = MuonInfo->MuTrgMatchFilterTrgObjPt[BInfo->uj_rfmu1_index[j]*MuonInfo->MuTrgMatchFilterSize+0];
    Jmu1TrgMatchFilterEta[typesize] = MuonInfo->MuTrgMatchFilterTrgObjEta[BInfo->uj_rfmu1_index[j]*MuonInfo->MuTrgMatchFilterSize+0];
    Jmu1TrgMatchFilterPhi[typesize] = MuonInfo->MuTrgMatchFilterTrgObjPhi[BInfo->uj_rfmu1_index[j]*MuonInfo->MuTrgMatchFilterSize+0];
    Jmu1isTriggered[typesize] = MuonInfo->isTriggered[BInfo->uj_rfmu1_index[j]*MuonInfo->MuTrgMatchFilterSize+0];
    Jmu2TrgMatchFilterE[typesize] = MuonInfo->MuTrgMatchFilterTrgObjE[BInfo->uj_rfmu2_index[j]*MuonInfo->MuTrgMatchFilterSize+0];
    Jmu2TrgMatchFilterPt[typesize] = MuonInfo->MuTrgMatchFilterTrgObjPt[BInfo->uj_rfmu2_index[j]*MuonInfo->MuTrgMatchFilterSize+0];
    Jmu2TrgMatchFilterEta[typesize] = MuonInfo->MuTrgMatchFilterTrgObjEta[BInfo->uj_rfmu2_index[j]*MuonInfo->MuTrgMatchFilterSize+0];
    Jmu2TrgMatchFilterPhi[typesize] = MuonInfo->MuTrgMatchFilterTrgObjPhi[BInfo->uj_rfmu2_index[j]*MuonInfo->MuTrgMatchFilterSize+0];
    Jmu2isTriggered[typesize] = MuonInfo->isTriggered[BInfo->uj_rfmu2_index[j]*MuonInfo->MuTrgMatchFilterSize+0];

    b4P->SetPxPyPzE(mu1px+mu2px,
                    mu1py+mu2py,
                    mu1pz+mu2pz,
                    mu1E+mu2E);
    Jmass_unfitted[typesize] = b4P->Mag();

    if(!REAL)
      {
        Jgen[typesize] = 0;
        Jgen[typesize]+=33;
        JgenIndex[typesize] = -1;
        Jgenpt[typesize] = -1;
        JgencollisionId[typesize] = -1;
        Jgeneta[typesize] = -20;
        Jgenphi[typesize] = -20;
        Jgeny[typesize] = -1;
        // int bGenIdxMu1=-1;
        // int bGenIdxMu2=-1;
        int ujGenIdxMu1=-1;
        int ujGenIdxMu2=-1;

        if(MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[j]]>-1)
          {
            int level =0;
            if(abs(GenInfo->pdgId[MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[j]]])==13)
              {
                level=1;
                int jmurad = 0;
                int muidx = MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[j]];
                while(GenInfo->mo1[muidx]>-1)
                  {
                    if(abs(GenInfo->pdgId[GenInfo->mo1[muidx]])!=13) break;
                    muidx = GenInfo->mo1[muidx];
                    jmurad++;
                  }
                if(GenInfo->mo1[muidx]>-1)
                  {
                    if(GenInfo->pdgId[GenInfo->mo1[muidx]]==443)
                      {
                        ujGenIdxMu1 = GenInfo->mo1[muidx];
                        level = 3;
                        if(jmurad) level = 4;
                        // bGenIdxMu1 = GenInfo->mo1[ujGenIdxMu1];
                      } 
                  }
              }
            Jgen[typesize]+=(level*100);
          }

        if(MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[j]]>-1)
          {
            int level =0;
            if(abs(GenInfo->pdgId[MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[j]]])==13)
              {
                level=1;
                int jmurad = 0;
                int muidx = MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[j]];
                while(GenInfo->mo1[muidx]>-1)
                  {
                    if(abs(GenInfo->pdgId[GenInfo->mo1[muidx]])!=13) break;
                    muidx = GenInfo->mo1[muidx];
                    jmurad++;
                  }
                if(GenInfo->mo1[muidx]>-1)
                  {
                    if(GenInfo->pdgId[GenInfo->mo1[muidx]]==443)
                      {
                        ujGenIdxMu2 = GenInfo->mo1[muidx];
                        level = 3;
                        if(jmurad) level = 4;
                        // bGenIdxMu2 = GenInfo->mo1[ujGenIdxMu2];
                      } 
                  }
              }
            Jgen[typesize]+=(level*1000);
          }

        if(ujGenIdxMu1!=-1 && ujGenIdxMu1==ujGenIdxMu2)
          {
            int level=2;
            JgenIndex[typesize] = ujGenIdxMu1;
            int bPDG = abs(GenInfo->pdgId[GenInfo->mo1[ujGenIdxMu1]]);
            bPDG /= 100;
            bPDG = bPDG%10;
            if(bPDG==5) { level = 3; }
            Jgen[typesize]+=(level*10000);
          }

        if(Jgen[typesize]>=23333)
          {
            int tgenIndex = JgenIndex[typesize];
            Jgenpt[typesize] = GenInfo->pt[tgenIndex];
            JgencollisionId[typesize] = GenInfo->collisionId[tgenIndex];
            Jgeneta[typesize] = GenInfo->eta[tgenIndex];
            Jgenphi[typesize] = GenInfo->phi[tgenIndex];
            b4P->SetXYZM(GenInfo->pt[tgenIndex]*cos(GenInfo->phi[tgenIndex]),
                         GenInfo->pt[tgenIndex]*sin(GenInfo->phi[tgenIndex]),
                         GenInfo->pt[tgenIndex]*sinh(GenInfo->eta[tgenIndex]),
                         GenInfo->mass[tgenIndex]);
            Jgeny[typesize] = b4P->Rapidity();
          }
      }//!REAL

  }
 
  bool signalGen(int Btype, int j, GenInfoBranches *GenInfo)
  {//{{{

    if(Btype==8 || Btype==9)
      {
        int flag=0;
        if(abs(GenInfo->pdgId[j])==JPSI_PDGID&&GenInfo->nDa[j]==2&&GenInfo->da1[j]!=-1&&GenInfo->da2[j]!=-1)
          {
            if(abs(GenInfo->pdgId[GenInfo->da1[j]])==13&&abs(GenInfo->pdgId[GenInfo->da2[j]])==13)
              {
                int bPDG = 0;
                if(GenInfo->mo1[j]!=-1)
                  {
                    bPDG = abs(GenInfo->pdgId[GenInfo->mo1[j]]);
                    bPDG /= 100;
                    bPDG = bPDG%10;
                  }
                if(bPDG==5)
                  {
                    if(Btype==9) flag++;
                  }
                else
                  {
                    if(Btype==8) flag++;
                  }
              }
          }
        return flag;
      }
    else
    {
      std::vector<float> BId;
      float MId,tk1Id,tk2Id;
      int twoTks;
      //tk1:positive, tk2:negtive
      if(Btype==1)
        {
          BId.push_back(521);//B+-
          MId = -1;
          tk1Id = 321;//K+-
          tk2Id = -1;
          twoTks = 0;
        }
      if(Btype==2)
        {
          BId.push_back(521);//B+-
          MId = -1;
          tk1Id = 211;//pi+-
          tk2Id = -1;
          twoTks = 0;
        }
      if(Btype==3)
        {
          BId.push_back(511);//B0
          MId = 310;//Ks
          tk1Id = 211;//pi+
          tk2Id = -211;//pi-
          twoTks = 1;
        }
      if(Btype==4)
        {
          BId.push_back(511);//B0
            MId = 313;//K*0
            tk1Id = 321;//K+
            tk2Id = 211;//pi-
            twoTks = 1;
          }
      if(Btype==6)
        {
          BId.push_back(531);//Bs
          MId = 333;//phi
            tk1Id = 321;//K+
            tk2Id = -321;//K-
          twoTks = 1;
        }
      if(Btype==7)
      {            
        BId.push_back(20443);   //chic1
        BId.push_back(100443);  //psi'
        BId.push_back(9920443); //X3872
        MId = 113;   //rho
        tk1Id = 211; //pi+-
        tk2Id = 211; //pi+-
        twoTks = 1;
      }
      
      int flag=0; 
      if(isBId(abs(GenInfo->pdgId[j]), BId))
      {
        if(GenInfo->nDa[j]>=2&&GenInfo->da1[j]!=-1&&GenInfo->da2[j]!=-1)
        {
          if(abs(GenInfo->pdgId[GenInfo->da1[j]])==443)//jpsi
          {
            if(GenInfo->da1[GenInfo->da1[j]]!=-1&&GenInfo->da2[GenInfo->da1[j]]!=-1)
            {
              if(abs(GenInfo->pdgId[GenInfo->da1[GenInfo->da1[j]]])==13&&abs(GenInfo->pdgId[GenInfo->da2[GenInfo->da1[j]]])==13)
              {
                if(!twoTks){ 
                  if(abs(GenInfo->pdgId[GenInfo->da2[j]])==abs(tk1Id)) flag++;
                }
                else
                {
                  if(abs(GenInfo->pdgId[GenInfo->da2[j]])==MId) // w/ resonance
                  {
                    if(GenInfo->da1[GenInfo->da2[j]]!=-1 && GenInfo->da2[GenInfo->da2[j]]!=-1)
                    {
                      if( ( (abs(GenInfo->pdgId[GenInfo->da1[GenInfo->da2[j]]])==abs(tk1Id)) && (abs(GenInfo->pdgId[GenInfo->da2[GenInfo->da2[j]]])==abs(tk2Id)) ) ||
                          ( (abs(GenInfo->pdgId[GenInfo->da1[GenInfo->da2[j]]])==abs(tk2Id)) && (abs(GenInfo->pdgId[GenInfo->da2[GenInfo->da2[j]]])==abs(tk1Id)) ) )flag++;
                    }
                  }
                  else if(GenInfo->da3[j]!=-1 && Btype==7) // w/o resonance
                  {
                    if(abs(GenInfo->pdgId[GenInfo->da2[j]])==abs(tk1Id) && abs(GenInfo->pdgId[GenInfo->da3[j]])==abs(tk2Id)) flag++; 
                  }
                }
              }
            }
          }
        }
      }
      return flag;
    }
  }//}}}

  template<typename T>
  bool isBId(int pdgId, std::vector<T> BId)
  {
    bool match = false;
    for(auto& id : BId)
      { if(pdgId==id) { match = true; break; } }
    return match;
  }
};//}}}

#endif
