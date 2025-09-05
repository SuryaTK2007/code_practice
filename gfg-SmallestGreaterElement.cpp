#include <bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n) {
    int* res = new int[n];
    set<int> s(arr, arr + n);
    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound(arr[i]);
        if (it != s.end()) res[i] = *it;
        else res[i] = -10000000;
    }

    return res;
}
int main() {
    int arr[] = {6, 3, 9, 8, 10, 2, 1, 15, 7};
    int n = 9;
    int* ans = greaterElement(arr, n);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
    delete[] ans;
    return 0;
}
