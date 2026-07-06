#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    int prev = arr[0][0];
    
    // Left column
    for (int i = 0; i < n - 1; i++)
        arr[i][0] = arr[i + 1][0];

    // Bottom row
    for (int j = 0; j < n - 1; j++)
        arr[n - 1][j] = arr[n - 1][j + 1];

    // Right column
    for (int i = n - 1; i > 0; i--)
        arr[i][n - 1] = arr[i - 1][n - 1];

    // Top row
    for (int j = n - 1; j > 1; j--)
        arr[0][j] = arr[0][j - 1];

    arr[0][1] = prev;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j];
        cout << '\n';
    }

    return 0;
}