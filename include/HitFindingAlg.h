//
// Created by dphan on 2/3/19.
//

#ifndef PEAKFINDER_HITFINDINGALG_H
#define PEAKFINDER_HITFINDINGALG_H

#include <map>
#include <vector>

template <class T>
typedef struct hit_t {
    T TStartInNanoSec;
    T TPeakInNanoSec;
    T IntegratedChargeInVoltNanoSec;
    T AmplitudeInMiliVolt;
    T RiseTimeInNanoSec;
    T FallTimeInNanoSec;
};

template <class T>
class HitFindingAlg {
public:

public:
    inline explicit HitFindingAlg(const std::vector<T>& waveform) : _Waveform(&waveform) {}
    inline virtual ~HitFindingAlg() = default;

    inline std::map<size_t, hit_t<T> > GetHitCollection() const { return _HitCollection; }
    inline void SetThreshold(T threshold) { _Threhold = threshold; }

private:
    std::vector<T>* _Waveform;
    std::map<size_t, hit_t<T> > _HitCollection;
    T _Pedestal;
    T _NoiseSigma;
    T _Threhold;

private:
    void Go();
    void FindPedestal();
};




#endif //PEAKFINDER_HITFINDINGALG_H
