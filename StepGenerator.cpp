//
// Created by erwan on 11/12/24.
//

#include "StepGenerator.h"
StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {}

std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size);
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 1);

    series[0] = 0;
    for (int i = 1; i < size; ++i) {
        if (distribution(generator) == 0) {
            series[i] = series[i - 1];
        } else {
            series[i] = static_cast<double>(rand() % 101);
        }
    }
    return series;
}