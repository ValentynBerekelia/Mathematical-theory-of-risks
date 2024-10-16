#include <iostream>
#include <cmath>
using namespace std;
#include <iostream>
#include <cmath>
using namespace std;

double utility(double x) {
    return log(x + 30);
}
double findCertaintyEquivalent(double expectedUtility) {
    return exp(expectedUtility) - 30;
}
double expectedUtilit(double prob, double lottery[]) {
    double result = prob * utility(lottery[0]) + prob * utility(lottery[1]);
    return result;
}

void choiceLottery(double r1, double r2, double r3) {
    if (r1 <= r2 && r1 <= r3) {
        cout << "The person will choose Lottery 1." << endl;
    }
    else if (r2 <= r1 && r2 <= r3) {
        cout << "The person will choose Lottery 2." << endl;
    }
    else {
        cout << "The person will choose Lottery 3." << endl;
    }
}
int main() {
    double lottery1[] = { -20, -10 };
    double lottery2[] = { -25, -15 };
    double lottery3[] = { -29, -19 };
    double prob = 0.5;
    double expectedWinnings1 = (lottery1[0] + lottery1[1]) / 2;
    double expectedWinnings2 = (lottery2[0] + lottery2[1]) / 2;
    double expectedWinnings3 = (lottery3[0] + lottery3[1]) / 2;

    double expectedUtility1 = expectedUtilit(prob, lottery1);

    double expectedUtility2 = expectedUtilit(prob, lottery2);

    double expectedUtility3 = expectedUtilit(prob, lottery3);

    double certaintyEquivalent1 = findCertaintyEquivalent(expectedUtility1);
    double certaintyEquivalent2 = findCertaintyEquivalent(expectedUtility2);
    double certaintyEquivalent3 = findCertaintyEquivalent(expectedUtility3);
    //risk
    double riskPremium1 = expectedWinnings1 - certaintyEquivalent1;
    double riskPremium2 = expectedWinnings2 - certaintyEquivalent2;
    double riskPremium3 = expectedWinnings3 - certaintyEquivalent3;

    cout << "Lottery 1: " << endl;
    cout << "  Expected Winnings: " << expectedWinnings1 << endl;
    cout << "  Expected Utility: " << expectedUtility1 << endl;
    cout << "  Certainty Equivalent: " << certaintyEquivalent1 << endl;
    cout << "  Risk Premium: " << riskPremium1 << endl;
    cout << endl;

    cout << "Lottery 2: " << endl;
    cout << "  Expected Winnings: " << expectedWinnings2 << endl;
    cout << "  Expected Utility: " << expectedUtility2 << endl;
    cout << "  Certainty Equivalent: " << certaintyEquivalent2 << endl;
    cout << "  Risk Premium: " << riskPremium2 << endl;
    cout << endl;

    cout << "Lottery 3: " << endl;
    cout << "  Expected Winnings: " << expectedWinnings3 << endl;
    cout << "  Expected Utility: " << expectedUtility3 << endl;
    cout << "  Certainty Equivalent: " << certaintyEquivalent3 << endl;
    cout << "  Risk Premium: " << riskPremium3 << endl;
    cout << endl;

    choiceLottery(riskPremium1, riskPremium2, riskPremium3);
}
