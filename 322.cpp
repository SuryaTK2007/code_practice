#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i, int remaining, vector<int>& coins, vector<vector<int>>&memo) {
        if (remaining == 0) return 0;              
        if (remaining < 0 || i >= (int)coins.size()) return -1;
        if (memo[i][remaining] != -2) return memo[i][remaining];
        int take = helper(i, remaining - coins[i], coins, memo);
        if (take != -1) take += 1;   
        int skip = helper(i + 1, remaining, coins, memo);
        int ans;
        if (take == -1 && skip == -1) ans=-1;
        else if (take == -1) ans=skip;
        else if (skip == -1) ans=take;
        else ans=min(take, skip);
        return memo[i][remaining]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -2));
        return helper(0, amount, coins, memo);
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout<<sol.coinChange(coins, amount) << endl;
    return 0;
}
