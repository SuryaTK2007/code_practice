#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int count = 0;
        for (int k = 2; k * k < n; k++) {
            if (isPrime[k]) {
                for (int i = k * k; i < n; i += k) {
                    isPrime[i] = false;
                }
            }
        }
        for (int i = 2; i < n; i++) {
            if (isPrime[i])
                count++;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.countPrimes(n) << "\n";
}
