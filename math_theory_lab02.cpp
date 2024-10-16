#include <iostream>
#include <cmath>
using namespace std;
double expectedValue(double values[], double probabilities[], int size) {
    double result = 0.0;
    for (int i = 0; i < size; ++i) {
        result += values[i] * probabilities[i];
    }
    return result;
}

double variance(double values[], double probabilities[], double mean, int size) {
    double result = 0.0;
    for (int i = 0; i < size; ++i) {
        result += probabilities[i] * pow(values[i] - mean, 2);
    }
    return result;
}

double standardDeviation(double variance) {
    return sqrt(variance);
}

double coefficientOfVariation(double std_dev, double mean) {
    return std_dev / mean;
}

void optimalChoice(double expected1,double expected2) {
    if (expected1 > expected2) {
        cout << "Optimal choice: First package" << endl;
    }
    else if (expected2 > expected1) {
        cout << "Optimal choice: Second package" << endl;
    }
    else {
        cout << "Both packages have the same expected profit." << endl;
    }
}

int main() {
    double values1[] = { 40000, 10000 };
    double probabilities1[] = { 0.5, 0.5 };

    double values2[] = { 30000, 5000 };
    double probabilities2[] = { 0.5, 0.5 };

    double expected1 = expectedValue(values1, probabilities1, 2);
    double expected2 = expectedValue(values2, probabilities2, 2);

    double variance1 = variance(values1, probabilities1, expected1, 2);
    double variance2 = variance(values2, probabilities2, expected2, 2);

    double std_dev1 = standardDeviation(variance1);
    double std_dev2 = standardDeviation(variance2);

    double cv1 = coefficientOfVariation(std_dev1, expected1);
    double cv2 = coefficientOfVariation(std_dev2, expected2);

    cout << "First package:" << endl;
    cout << "Expected profit: " << expected1 << endl;
    cout << "Variance: " << variance1 << endl;
    cout << "Standard deviation: " << std_dev1 << endl;
    cout << "Coefficient of variation: " << cv1 << endl;
    cout << endl;
    cout << "Second package:" << endl;
    cout << "Expected profit: " << expected2 << endl;
    cout << "Variance: " << variance2 << endl;
    cout << "Standard deviation: " << std_dev2 << endl;
    cout << "Coefficient of variation: " << cv2 << endl;
    cout << endl;
    optimalChoice(expected1, expected2);

    return 0;
}
