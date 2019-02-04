#ifndef Waveform_h
#define Waveform_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <iostream>

class WaveformReader {
public:
    WaveformReader(std::string fileName, TTree *tree = 0);
    virtual ~WaveformReader();

    virtual void GetWaveform(Long64_t entry, double* wf);

private:
    TTree *fChain;
    Int_t fCurrent;

    UShort_t waveform[1950];
    TBranch *b_waveform;

    virtual Int_t GetEntry(Long64_t entry);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void Init(TTree *tree);
};

#endif
