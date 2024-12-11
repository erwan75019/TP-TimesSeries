//
// Created by erwan on 11/12/24.
//

#include "KNN.h"
KNN::KNN(int k, const std::string& similarityMeasure) 
    : k(k), similarityMeasure(similarityMeasure) {}

double KNN::euclideanDistance(const std::vector<double>& a, const std::vector<double>& b) const {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return std::sqrt(sum);
}

double KNN::evaluate(const TimeSeriesDataset& train, const TimeSeriesDataset& test, const std::vector<int>& groundTruth) const {
    int correct = 0;
    const auto& trainData = train.getData();
    const auto& trainLabels = train.getLabels();
    const auto& testData = test.getData();

    for (size_t i = 0; i < testData.size(); ++i) {
        std::vector<std::pair<double, int>> distances;
        for (size_t j = 0; j < trainData.size(); ++j) {
            double distance = euclideanDistance(testData[i], trainData[j]);
            distances.emplace_back(distance, trainLabels[j]);
        }
        std::sort(distances.begin(), distances.end());

        std::vector<int> neighborLabels;
        for (int n = 0; n < k; ++n) {
            neighborLabels.push_back(distances[n].second);
        }

        int predictedLabel = std::max_element(neighborLabels.begin(), neighborLabels.end(),
                                              [&neighborLabels](int a, int b) {
                                                  return std::count(neighborLabels.begin(), neighborLabels.end(), a) <
                                                         std::count(neighborLabels.begin(), neighborLabels.end(), b);
                                              }) - neighborLabels.begin();

        if (predictedLabel == groundTruth[i]) {
            ++correct;
        }
    }


    return static_cast<double>(correct) / groundTruth.size();
}