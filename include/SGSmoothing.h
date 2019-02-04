#ifndef __SGSMOOTH_HPP__
#define __SGSMOOTH_HPP__

#include <vector>

std::vector<double> sg_smooth(const std::vector<double> &v, const int w, const int deg);
std::vector<double> sg_derivative(const std::vector<double> &v, const int w,
                                  const int deg, const double h = 1.0);

class SGSmoothing {
public:
    static void Smooth(size_t nsamples, double* in, double* out, const int w, const int deg);
    static void Derivative(size_t nsamples, double* in, double* out, const int w, const int deg, const double h = 1.0);
};

#endif // __SGSMOOTH_HPP__
