//
// Created by dphan on 2/1/19.
//

#include <PlotUtil.h>

void PlotUtil::Plot(double *wf, std::string plotName) {
    double* timeArray(new double[1950]);
    for (size_t idx = 0; idx < 1950; idx++) {
        *(timeArray + idx) = (double)idx;
    }

    double minVal = *std::min_element(wf, wf + 1950);
    double maxVal = *std::max_element(wf, wf + 1950);

    TGraph* gr = new TGraph(1950, timeArray, wf);
    gr->GetXaxis()->SetRangeUser(0, 1950);
    gr->GetYaxis()->SetRangeUser(minVal - 0.5, maxVal + 0.5);

    TLine* line = new TLine(0, 0, 1950, 0);
    line->SetLineColor(kRed);

    TCanvas* c = new TCanvas();
    gr->Draw("AL");
    line->Draw();
    c->SaveAs(plotName.c_str());

    delete timeArray;
}

void PlotUtil::Plot(double *wf1, double *wf2, PlotUtil::PlotOptions_t opt, std::string plotName) {
    double* timeArray(new double[1950]);
    for (size_t idx = 0; idx < 1950; idx++) {
        *(timeArray + idx) = (double)idx;
    }

    double minVal = *std::min_element(wf1, wf1 + 1950);
    double maxVal = *std::max_element(wf1, wf1 + 1950);

    TGraph* gr1 = new TGraph(1950, timeArray, wf1);
    gr1->GetXaxis()->SetRangeUser(0, 1950);
    gr1->GetYaxis()->SetRangeUser(minVal - 50, maxVal + 50);

    TGraph* gr2 = new TGraph(1950, timeArray, wf2);
    gr2->GetXaxis()->SetRangeUser(0, 1950);
    gr2->SetLineColor(kRed);

    TCanvas* c = new TCanvas();
    gr1->Draw("AL");
    gr2->Draw("SAME");
    c->SaveAs(plotName.c_str());

    delete timeArray;
}
