#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int left = 0, right = n - 1;
        long long leftSum = 0, rightSum = 0;
        int ans = 0;
        
        while (left <= right) {
            if (leftSum <= rightSum) {
                leftSum += a[left];
                left++;
            } else {
                rightSum += a[right];
                right--;
            }

            if (leftSum == rightSum)
                ans = left + (n - right - 1);
        }

        cout << ans << endl;
    }
    return 0;
}