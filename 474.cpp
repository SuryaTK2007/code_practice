#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<string>& strs, int m, int n, int step, vector<vector<vector<int>>>& dp) {
        if (step == strs.size()) return 0;
        if (dp[step][m][n] != -1) return dp[step][m][n];
        int zcount = 0, ocount = 0;
        for (char ch : strs[step]) {
            if (ch == '0') zcount++;
            else ocount++;
        }
        int skip = helper(strs, m, n, step + 1, dp);
        int take = 0;
        if (m >= zcount && n >= ocount)
            take = 1 + helper(strs, m - zcount, n - ocount, step + 1, dp);
        return dp[step][m][n] = max(skip, take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(strs, m, n, 0, dp);
    }
};

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    Solution s;
    cout << s.findMaxForm(strs, m, n);
}
