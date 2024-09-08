#include <iostream>
#include <string>
#include <map>
using namespace std;
int getRating(const string& feeling) {
    map<string, int> ratings = {
        {"дуже погано", 1},
        {"погано", 3},
        {"посередньо", 6},
        {"добре", 8},
        {"дуже добре", 10}
    };

    if (ratings.find(feeling) != ratings.end()) {
        return ratings[feeling];
    }
    else {
        return 0;
    }
}

int main() {
    string feeling;
    double rainProbability;


    cout << "Enter your feeling: ";
    getline(cin, feeling);
    cout << "Enter the probability of rain: ";
    cin >> rainProbability;



    int rating = getRating(feeling);
    double homeBenefit = rainProbability * rating + (1 - rainProbability) * 8;
    double forestBenefit = rainProbability * 1 + (1 - rainProbability) * 10;

    cout << "Benefit of staying at home: " << homeBenefit << endl;
    cout << "Benefit of going to the forest: " << forestBenefit << endl;

    if (forestBenefit > homeBenefit) {
        cout << "Recommendation: Go to the forest." << endl;
    }
    else {
        cout << "Recommendation: Stay at home." << endl;
    }

    return 0;
}
