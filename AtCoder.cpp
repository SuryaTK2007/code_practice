#include <bits/stdc++.h>
using namespace std;

int main() {
    int hr = 21;
    int mn = 0;
    int k;
    cin >> k;
    int reshr = k / 60;
    int resmin = k % 60;
    hr += reshr;
    mn += resmin;
    cout << hr << ":";
    if (mn < 10)
        cout << "0";
    cout << mn;
}