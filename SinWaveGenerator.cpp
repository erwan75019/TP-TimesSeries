//
// Created by erwan on 11/12/24.
//

#include "SinWaveGenerator.h"
SinWaveGenerator::SinWaveGenerator(double amplitude, double frequency, double phase, int seed) 
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size);
    for (int i = 0; i < size; ++i) {
        series[i] = amplitude * sin(frequency * i + phase);
    }
    return series;
}