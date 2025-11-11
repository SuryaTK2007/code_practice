#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int W, vector<int>& val, vector<int>& wt, int i, vector<vector<int>>& dp) {
        if (i == val.size()) return 0;
        if (dp[i][W] != -1) return dp[i][W];
        int x = val[i];
        int y = wt[i];
        int skip = helper(W, val, wt, i + 1, dp);
        int take = 0;
        if (W >= y) take = x + helper(W - y, val, wt, i + 1, dp);
        return dp[i][W] = max(take, skip);
    }
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return helper(W, val, wt, 0, dp);
    }
};

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    Solution s;
    cout << s.knapsack(W, val, wt);
}
