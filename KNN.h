#ifndef KNN_H
#define KNN_H

#include "TimeSeriesDataset.h"
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

class KNN {
private:
    int k;
    std::string similarityMeasure;

    double euclideanDistance(const std::vector<double>& a, const std::vector<double>& b) const;
    // Ajouter d'autres fonctions de similarité si nécessaire.

public:
    KNN(int k, const std::string& similarityMeasure);
    double evaluate(const TimeSeriesDataset& train, const TimeSeriesDataset& test, const std::vector<int>& groundTruth) const;
};

#endif 