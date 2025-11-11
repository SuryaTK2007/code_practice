#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int W, vector<int>& val, vector<int>& wt, int i) {
        if (i == val.size()) return 0;
        int x = val[i];
        int y = wt[i];
        int skip = helper(W, val, wt, i + 1);
        int take = 0;
        if (W >= y) take = x + helper(W - y, val, wt, i + 1);
        return max(take, skip);
    }
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        return helper(W, val, wt, 0);
    }
};

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    Solution s;
    cout << s.knapsack(W, val, wt);
}
