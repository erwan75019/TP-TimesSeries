//
// Created by erwan on 11/12/24.
//
#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <cmath>

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;
    double frequency;
    double phase;

public:
    SinWaveGenerator(double amplitude = 1.0, double frequency = 1.0, double phase = 0.0, int seed = 0);
    std::vector<double> generateTimeSeries(int size) override;
};

#endif // SINWAVEGENERATOR_H