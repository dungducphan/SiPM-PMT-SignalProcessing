#include "WaveformReader.h"

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

WaveformReader::WaveformReader(std::string fileName, TTree *tree) : fChain(0) {
    if (tree == 0) {
        TFile *f = (TFile *) gROOT->GetListOfFiles()->FindObject(fileName.c_str());
        if (!f || !f->IsOpen()) {
            f = new TFile(fileName.c_str());
        }
        f->GetObject("TrackTree_SSP18_CH6_6", tree);

    }
    Init(tree);
}

WaveformReader::~WaveformReader() {
    if (!fChain) return;
    delete fChain->GetCurrentFile();
}

Int_t WaveformReader::GetEntry(Long64_t entry) {
// Read contents of entry.
    if (!fChain) return 0;
    return fChain->GetEntry(entry);
}

Long64_t WaveformReader::LoadTree(Long64_t entry) {
// Set the environment to read one entry
    if (!fChain) return -5;
    Long64_t centry = fChain->LoadTree(entry);
    if (centry < 0) return centry;
    if (fChain->GetTreeNumber() != fCurrent) {
        fCurrent = fChain->GetTreeNumber();
    }
    return centry;
}

void WaveformReader::Init(TTree *tree) {
    if (!tree) return;
    fChain = tree;
    fCurrent = -1;
    fChain->SetMakeClass(1);

    fChain->SetBranchAddress("waveform", waveform, &b_waveform);

}

void WaveformReader::GetWaveform(Long64_t entry, double* wf) {
    if (fChain == 0) return;
    if (LoadTree(entry) < 0) return;
    GetEntry(entry);

    for (size_t idx = 0; idx < 1950; idx++) {
        *(wf + idx) = (double) waveform[idx];
    }
}
