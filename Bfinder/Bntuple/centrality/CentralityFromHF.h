// Offline centrality from the stored hiHF (HF tower ET sum), with any table
// dumped by dump_centrality_edges.py (nominal / SysUp / SysDown).
//
//   CentralityEdges nom("edges/PbPb2024_data_Nominal.txt");
//   int hiBin = nom.hiBin(hiHF);     // 0..199, same as CentralityBinProducer
//   double cent = hiBin / 2.;        // centrality in %  (CentBin = hiBin / 2)
#ifndef CENTRALITY_FROM_HF_H
#define CENTRALITY_FROM_HF_H

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class CentralityEdges {
public:
  explicit CentralityEdges(const std::string& file) {
    std::ifstream in(file);
    if (!in) throw std::runtime_error("cannot open " + file);
    std::string line;
    while (std::getline(in, line)) {
      if (line.empty() || line[0] == '#') continue;
      edges_.push_back(std::stod(line));
    }
    if (edges_.size() != 200) throw std::runtime_error("expected 200 edges in " + file);
  }

  // Same logic as RecoHI/HiCentralityAlgos/plugins/CentralityBinProducer.cc; -1 if no centrality stored
  int hiBin(float hiHF) const {
    if (hiHF < 0) return -1;
    for (size_t i = 0; i < edges_.size(); ++i)
      if (hiHF >= edges_[i] && hiHF != 0) return i;
    return edges_.size() - 1;
  }

private:
  std::vector<double> edges_;
};

#endif
