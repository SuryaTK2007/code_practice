#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
            
        long long ans = 0;

        // Find the first non-zero element.
        // Leading zeros don't matter because there is no dust
        // before them to move.
        int i = 0;
        while (i < n && a[i] == 0)
            i++;

        // We process only till n-2.
        // The last room can contain any amount of dust,
        // so we never need to move dust out of it.
        for (; i < n - 1; i++) {

            // Every unit of dust must be moved once to the right.
            // So add the amount of dust.
            ans += a[i];

            // If this room has 0 dust (after the first non-zero),
            // we must first bring one unit of dust here from the left
            // before continuing. This costs one extra operation.
            if (a[i] == 0)
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}