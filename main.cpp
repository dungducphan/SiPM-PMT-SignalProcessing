#include <iostream>

#include <QString>

#include <TString.h>

#include <WaveformReader.h>
#include <PlotUtil.h>
#include <SGSmoothing.h>

int main(int argc, char* argv[]) {
    WaveformReader* waveformReader = new WaveformReader("../Hodotracks-0.root");

    double* waveform = new double[1950];
    double* waveform_smoothed = new double[1950];
    double* waveform_derivative = new double[1950];

    QString tmp_string(argv[1]);
    unsigned int evt_id = tmp_string.toDouble();
//    unsigned int evt_id = 16;
    waveformReader->GetWaveform(evt_id, waveform);

    SGSmoothing::Smooth(1950, waveform, waveform_smoothed, 15, 3);
    SGSmoothing::Derivative(1950, waveform, waveform_derivative, 61, 3);

    PlotUtil::Plot(waveform, waveform_smoothed, PlotUtil::kSinglePad, Form("Waveform_%i.pdf", evt_id));
    PlotUtil::Plot(waveform_derivative, Form("Derivative_%i.pdf", evt_id));

    delete waveform;
    delete waveform_smoothed;

    return 0;
}