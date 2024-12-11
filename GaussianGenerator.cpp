//
// Created by erwan on 11/12/24.
//

#include "GaussianGenerator.h"
GaussianGenerator::GaussianGenerator(double mean, double stddev, int seed) 
    : TimeSeriesGenerator(seed), mean(mean), stddev(stddev) {}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size);
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(mean, stddev);

    for (int i = 0; i < size; ++i) {
        series[i] = distribution(generator);
    }
    return series;
}