#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solveTest() {
    int totalElements, groupSize;
    cin >> totalElements >> groupSize;

    vector<int> elementCount(totalElements + 1, 0);
    for (int i = 0; i < totalElements; i++) {
        int elementValue;
        cin >> elementValue;
        if (elementValue <= totalElements) {
            elementCount[elementValue]++;
        }
    }

    int prefixCount = 0;
    int maxPossibleMex = 0;

    for (int currentVal = 0; currentVal <= totalElements; currentVal++) {
        prefixCount += elementCount[currentVal];
        long long requiredElements = 1LL * (currentVal + 1) * groupSize;

        if (elementCount[currentVal] < 1 || prefixCount < requiredElements) {
            break;
        }
        maxPossibleMex = currentVal + 1;
    }

    cout << maxPossibleMex << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        solveTest();
    }

    return 0;
}
