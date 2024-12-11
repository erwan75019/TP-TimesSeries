#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <cmath>
#include <random>

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stddev;

public:
    GaussianGenerator(double mean = 0.0, double stddev = 1.0, int seed = 0);
    std::vector<double> generateTimeSeries(int size) override;
};

#endif // GAUSSIANGENERATOR_H