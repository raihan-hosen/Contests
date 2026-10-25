#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solveTest() {
    int totalElements;
    cin >> totalElements;

    vector<long long> inputArray(totalElements);
    bool hasZeroElement = false;

    for (int i = 0; i < totalElements; i++) {
        cin >> inputArray[i];
        if (inputArray[i] == 0) {
            hasZeroElement = true;
        }
    }

    if (hasZeroElement) {
        cout << totalElements << endl;
        return;
    }

    sort(inputArray.begin(), inputArray.end());

    int maxGoodLength = 0;
    for (int i = 0; i < totalElements; i++) {
        long long remainingElements = totalElements - i;
        if (remainingElements >= inputArray[i] + 1) {
            maxGoodLength = max(maxGoodLength, (int)remainingElements);
        }
    }

    cout << maxGoodLength << endl;
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
