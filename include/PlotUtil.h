#ifndef PEAKFINDER_PLOTUTIL_H
#define PEAKFINDER_PLOTUTIL_H

#include <iostream>

#include <TGraph.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TAxis.h>
#include <TLine.h>

class PlotUtil {
public:
    enum PlotOptions_t {
        kSinglePad
    };

public:
    static void Plot(double* wf, std::string plotName = "Plot.pdf");
    static void Plot(double* wf1, double* wf2, PlotOptions_t opt, std::string plotName = "Plot.pdf");
};


#endif //PEAKFINDER_PLOTUTIL_H
