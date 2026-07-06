#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        bool found = false;
        for (auto i : mp) {
            if (i.second >= 3) {
                cout << i.first << '\n';
                found = true;
                break;
            }
        }
        if (!found)
            cout << -1 << '\n';
    }
    return 0;
}