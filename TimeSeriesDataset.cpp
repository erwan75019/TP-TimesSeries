//
// Created by erwan on 11/12/24.
//

#include "TimeSeriesDataset.h"
TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain) 
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

void TimeSeriesDataset::zNormalizeSeries(std::vector<double>& series) {
    double mean = 0.0;
    double stddev = 0.0;

    for (double value : series) {
        mean += value;
    }
    mean /= series.size();

    for (double value : series) {
        stddev += (value - mean) * (value - mean);
    }
    stddev = std::sqrt(stddev / series.size());

    for (double& value : series) {
        value = (value - mean) / stddev;
    }
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    std::vector<double> newSeries = series;
    if (znormalize) {
        zNormalizeSeries(newSeries);
    }
    data.push_back(newSeries);
    labels.push_back(label);
    ++numberOfSamples;
    if (newSeries.size() > maxLength) {
        maxLength = newSeries.size();
    }
}

const std::vector<std::vector<double>>& TimeSeriesDataset::getData() const {
    return data;
}

const std::vector<int>& TimeSeriesDataset::getLabels() const {
    return labels;
}