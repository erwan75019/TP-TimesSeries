#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <cmath>

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    int maxLength;
    int numberOfSamples;

    void zNormalizeSeries(std::vector<double>& series);

public:
    TimeSeriesDataset(bool znormalize, bool isTrain);
    void addTimeSeries(const std::vector<double>& series, int label);
    const std::vector<std::vector<double>>& getData() const;
    const std::vector<int>& getLabels() const;
};

#endif // TIMESERIESDATASET_H