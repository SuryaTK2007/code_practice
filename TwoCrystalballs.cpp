#include <bits/stdc++.h>
using namespace std;

int two_crystal_balls(const vector<bool>& breaks) {
    int n = breaks.size();

    int jumpAmount = floor(sqrt(n));

    int i = jumpAmount;

    // First ball: jump in steps of sqrt(n)
    for (; i < n; i += jumpAmount) {
        if (breaks[i]) {
            break;
        }
    }

    // Step back to previous safe block
    i -= jumpAmount;

    // Second ball: linear search
    for (int j = 0; j < jumpAmount && i < n; ++j, ++i) {
        if (breaks[i]) {
            return i;
        }
    }

    return -1; // nothing breaks
}

int main() {
    // Example usage:
    vector<bool> b = {false, false, false, true, true, true};
    cout << two_crystal_balls(b) << "\n"; // prints 3
}
