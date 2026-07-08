#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, h, m;
        cin >> n >> h >> m;
        int current = h * 60 + m;
        int ans = 24 * 60;
        while (n--) {
            int ah, am;
            cin >> ah >> am;
            int alarm = ah * 60 + am;
            int diff = alarm - current;
            if (diff < 0)
                diff += 24 * 60;

            ans = min(ans, diff);
        }
        cout << ans / 60 << " " << ans % 60 << endl;
    }

    return 0;
}