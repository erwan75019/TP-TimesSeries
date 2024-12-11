#include "GaussianGenerator.h"
#include "SinWaveGenerator.h"
#include "StepGenerator.h"
#include "TimeSeriesDataset.h"
#include "KNN.h"
#include <iostream>

int main() {
    TimeSeriesDataset trainData(false, true);
    TimeSeriesDataset testData(false, false);

    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

 // Ajouter des séries au jeu d'entraînement
    trainData.addTimeSeries(gsg.generateTimeSeries(11), 0);
    trainData.addTimeSeries(gsg.generateTimeSeries(11), 0);
    trainData.addTimeSeries(swg.generateTimeSeries(11), 1);
    trainData.addTimeSeries(swg.generateTimeSeries(11), 1);
    trainData.addTimeSeries(stg.generateTimeSeries(11), 2);
    trainData.addTimeSeries(stg.generateTimeSeries(11), 2);


    // Ajouter des séries au jeu de test avec des labels par défaut
    testData.addTimeSeries(gsg.generateTimeSeries(11), 0); // Label par défaut 0
    testData.addTimeSeries(swg.generateTimeSeries(11), 1); // Label par défaut 1
    testData.addTimeSeries(stg.generateTimeSeries(11), 2); // Label par défaut 2

    std::vector<int> groundTruth = {0, 1, 2};

    KNN knn1(1, "euclidean_distance");
    std::cout << "Accuracy (k=1): " << knn1.evaluate(trainData, testData, groundTruth) << std::endl;

    KNN knn2(2, "euclidean_distance");
    std::cout << "Accuracy (k=2): " << knn2.evaluate(trainData, testData, groundTruth) << std::endl;

    KNN knn3(3, "euclidean_distance");
    std::cout << "Accuracy (k=3): " << knn3.evaluate(trainData, testData, groundTruth) << std::endl;

    return 0;
}