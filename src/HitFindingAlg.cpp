//
// Created by dphan on 2/3/19.
//

#include "HitFindingAlg.h"

template<class T>
void HitFindingAlg<T>::Go() {
    T negThr = -1.0 * _Threhold;
    float minadc = 0;

    typename std::vector<T>::iterator itr_begin = _Waveform->begin();
    typename std::vector<T>::iterator itr_end   = _Waveform->end();
    for (typename std::vector<T>::iterator itr = itr_begin; itr != itr_end; itr++) {
        T this_adc = *itr;
        T next_adc = *(itr + 1);
        if (this_adc < negThr && next_adc < negThr) {
            typename std::vector<T>::iterator backward_itr = itr;
            while (this_adc <= 0. && backward_itr != itr_begin) {
                backward_itr--;
                this_adc = *backward_itr;
            }
        }
    }



    // find the dips
    while (bin<(fDataSize-1)) {  // loop over ticks
        float thisadc = holder[bin];
        float nextadc = holder[bin+1];
        if (thisadc < negthr && nextadc < negthr) { // new region, require two ticks above threshold
            // step back to find zero crossing
            unsigned int place = bin;
            while (thisadc<=0 && bin>0) {
                bin--;
                thisadc=holder[bin];
            }
            float hittime = bin+thisadc/(thisadc-holder[bin+1]);
            maxTimes.push_back(hittime);

            // step back more to find the hit start time
            uint32_t stop;
            if (fIndCutoff<(int)bin) { stop=bin-fIndCutoff; } else { stop=0; }
            while (thisadc<threshold && bin>stop) {
                bin--;
                thisadc=holder[bin];
            }
            if (bin>=2) bin-=2;
            while (thisadc>threshold && bin>stop) {
                bin--;
                thisadc=holder[bin];
            }
            startTimes.push_back(bin+1);
            // now step forward from hit time to find end time, area of dip
            bin=place;
            thisadc=holder[bin];
            minadc=thisadc;
            bin++;
            totSig = fabs(thisadc);
            while (thisadc<negthr && bin<fDataSize) {
                totSig += fabs(thisadc);
                thisadc=holder[bin];
                if (thisadc<minadc) minadc=thisadc;
                bin++;
            }
            endTimes.push_back(bin-1);
            peakHeight.push_back(-1.0*minadc);
            charge.push_back(totSig);
            hitrms.push_back(5.0);
            // don't look for a new hit until it returns to baseline
            while (thisadc<0 && bin<fDataSize) {
                bin++;
                if (bin == fDataSize) break;
                thisadc=holder[bin];
            }
        } // end region
        bin++;
    } // loop over ticks
}
