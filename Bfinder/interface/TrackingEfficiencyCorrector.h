#ifndef Bfinder_Bfinder_TrackingEfficiencyCorrector_h
#define Bfinder_Bfinder_TrackingEfficiencyCorrector_h

#include <cmath>
#include <memory>
#include <string>
#include <utility>

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/FileInPath.h"
#include "FWCore/Utilities/interface/Exception.h"

#include "TFile.h"
#include "TH2F.h"
#include "TH3F.h"

namespace bfinder {

enum class SystemYear { kNone, kPPRef2024, kPbPb2023, kPbPb2024 };
enum class TrackSelectionVariation { kLoose, kNominal, kTight };

inline SystemYear systemYearFromString(const std::string& name) {
  if (name == "None" || name == "none")
    return SystemYear::kNone;
  if (name == "ppRef2024")
    return SystemYear::kPPRef2024;
  if (name == "PbPb2023")
    return SystemYear::kPbPb2023;
  if (name == "PbPb2024")
    return SystemYear::kPbPb2024;

  throw cms::Exception("Configuration")
      << "Unsupported Bfinder systemYear " << name
      << ". Expected None, ppRef2024, PbPb2023, or PbPb2024.";
}

inline bool isPbPb(SystemYear systemYear) {
  return systemYear == SystemYear::kPbPb2023 || systemYear == SystemYear::kPbPb2024;
}

inline const char* trackSelectionTag(TrackSelectionVariation variation) {
  switch (variation) {
    case TrackSelectionVariation::kLoose:
      return "Loose";
    case TrackSelectionVariation::kNominal:
      return "Nominal";
    case TrackSelectionVariation::kTight:
      return "Tight";
  }
  throw cms::Exception("LogicError") << "Unknown track-selection variation.";
}

class TrackingEfficiencyCorrector {
public:
  TrackingEfficiencyCorrector(SystemYear systemYear,
                              TrackSelectionVariation variation,
                              bool quiet = true);

  TrackingEfficiencyCorrector(const TrackingEfficiencyCorrector&) = delete;
  TrackingEfficiencyCorrector& operator=(const TrackingEfficiencyCorrector&) = delete;

  float getCorrection(float pt, float eta, int hiBin = -1) const;

private:
  static std::unique_ptr<TFile> openFile(const std::string& relativePath);

  template <typename Histogram>
  static Histogram* getHistogram(TFile& file, const char* name) {
    Histogram* histogram = nullptr;
    file.GetObject(name, histogram);
    if (!histogram) {
      throw cms::Exception("TrackingEfficiency")
          << "Histogram '" << name << "' is missing from " << file.GetName() << ".";
    }
    return histogram;
  }

  bool checkBounds(float pt, float eta, int hiBin) const;
  void warn(const std::string& message) const;

  SystemYear systemYear_;
  bool quiet_;

  std::unique_ptr<TFile> efficiencyFile_;
  std::unique_ptr<TFile> backgroundFile_;
  TH2F* efficiency2D_ = nullptr;
  TH2F* fake2D_ = nullptr;
  TH2F* secondary2D_ = nullptr;
  TH3F* efficiency3D_ = nullptr;
  TH3F* fake3D_ = nullptr;
};

inline std::unique_ptr<TFile> TrackingEfficiencyCorrector::openFile(const std::string& relativePath) {
  const edm::FileInPath resolvedPath(relativePath);
  std::unique_ptr<TFile> file(TFile::Open(resolvedPath.fullPath().c_str(), "READ"));
  if (!file || file->IsZombie()) {
    throw cms::Exception("TrackingEfficiency")
        << "Unable to open tracking-efficiency file '" << relativePath << "'.";
  }
  return file;
}

inline TrackingEfficiencyCorrector::TrackingEfficiencyCorrector(
    SystemYear systemYear,
    TrackSelectionVariation variation,
    bool quiet)
    : systemYear_(systemYear), quiet_(quiet) {
  const std::string selection = trackSelectionTag(variation);
  std::string tableDirectory;
  std::string efficiencyFileName;
  std::string backgroundFileName;

  if (systemYear_ == SystemYear::kPPRef2024) {
    tableDirectory = "Bfinder/Bfinder/data/TRKeffCOR/ppRef2024/tables/";
    efficiencyFileName = "Eff_ppref_2024_Pythia_QCD_pThat15_NopU_2D_" + selection + "_Official.root";
    backgroundFileName = "Eff_ppref_2024_Pythia_minBias_NopU_2D_" + selection + "_Official.root";
  } else if (systemYear_ == SystemYear::kPbPb2023) {
    tableDirectory = "Bfinder/Bfinder/data/TRKeffCOR/PbPb2023/tables/";
    efficiencyFileName = "GeneralTracks_2023_PythiaHydjetQCD_Official_Eff_3D_" + selection +
                         "_9thJune2025.root";
    backgroundFileName =
        "GeneralTracks_2023_HydjetMB_Official_Eff_3D_" + selection + "_9thJune2025.root";
  } else if (systemYear_ == SystemYear::kPbPb2024) {
    tableDirectory = "Bfinder/Bfinder/data/TRKeffCOR/PbPb2024/tables/";
    efficiencyFileName = "GeneralTracks_2024_PythiaHydjetQCD_CelloTune_Official_Eff_3D_" + selection +
                         "_13April2026.root";
    backgroundFileName = "GeneralTracks_2024_HydjetMB_CelloTune_Official_Eff_3D_" + selection +
                         "_13April2026.root";
  } else {
    throw cms::Exception("Configuration")
        << "No tracking-efficiency tables are configured for the selected systemYear.";
  }

  efficiencyFile_ = openFile(tableDirectory + efficiencyFileName);
  backgroundFile_ = openFile(tableDirectory + backgroundFileName);

  if (systemYear_ == SystemYear::kPPRef2024) {
    efficiency2D_ = getHistogram<TH2F>(*efficiencyFile_, "hEff_2D");
    fake2D_ = getHistogram<TH2F>(*backgroundFile_, "hFak_2D");
    secondary2D_ = getHistogram<TH2F>(*backgroundFile_, "hSec_2D");
  } else {
    efficiency3D_ = getHistogram<TH3F>(*efficiencyFile_, "hEff_3D");
    fake3D_ = getHistogram<TH3F>(*backgroundFile_, "hFak_3D");
  }
}

inline void TrackingEfficiencyCorrector::warn(const std::string& message) const {
  if (!quiet_)
    edm::LogWarning("TrackingEfficiency") << message;
}

inline bool TrackingEfficiencyCorrector::checkBounds(float pt, float eta, int hiBin) const {
  if (!std::isfinite(pt) || !std::isfinite(eta) || std::abs(eta) > 2.4f || pt < 0.f || pt > 500.f) {
    warn("Track lies outside the tracking-efficiency table range.");
    return false;
  }
  if (isPbPb(systemYear_) && (hiBin < 0 || hiBin > 199)) {
    warn("PbPb centrality bin lies outside [0, 199].");
    return false;
  }
  return true;
}

inline float TrackingEfficiencyCorrector::getCorrection(float pt, float eta, int hiBin) const {
  if (!checkBounds(pt, eta, hiBin))
    return 0.f;

  float efficiency = 0.f;
  float fake = 0.f;
  float secondary = 0.f;

  if (systemYear_ == SystemYear::kPPRef2024) {
    efficiency = efficiency2D_->GetBinContent(efficiency2D_->FindBin(eta, pt));
    fake = fake2D_->GetBinContent(fake2D_->FindBin(eta, pt));
    secondary = secondary2D_->GetBinContent(secondary2D_->FindBin(eta, pt));
  } else {
    efficiency = efficiency3D_->GetBinContent(efficiency3D_->FindBin(eta, pt, hiBin));
    fake = fake3D_->GetBinContent(fake3D_->FindBin(eta, pt, hiBin));
  }

  if (!std::isfinite(efficiency) || !std::isfinite(fake) || !std::isfinite(secondary) ||
      efficiency <= 0.001f) {
    warn("Invalid or very small tracking efficiency; returning zero correction.");
    return 0.f;
  }

  const float correction = systemYear_ == SystemYear::kPPRef2024
                               ? (1.f - fake) * (1.f - secondary) / efficiency
                               : (1.f - fake) / efficiency;
  if (!std::isfinite(correction) || correction < 0.f) {
    warn("Invalid tracking correction; returning zero correction.");
    return 0.f;
  }
  return correction;
}

}  // namespace bfinder

#endif
