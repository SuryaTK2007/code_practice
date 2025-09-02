#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        k = k % n; 
        for (int i = 0; i < n; i++) {
            cout << arr[(n - k + i) % n] << " ";
        }
        cout << "\n";
    }
    return 0;
}
