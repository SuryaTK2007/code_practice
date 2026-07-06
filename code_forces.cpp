#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        bool ok = true;
        int evenI = arr[0] % 2;
        for (int i = 0; i < n; i += 2) {
            if (arr[i] % 2 != evenI) {
                ok = false;
                break;
            }
        }
        if (ok && n > 1) {
            int oddI = arr[1] % 2;
            for (int i = 1; i < n; i += 2) {
                if (arr[i] % 2 != oddI) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}