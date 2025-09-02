#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i, int remaining, vector<int>& coins) {
        if (remaining == 0) return 0;              
        if (remaining < 0 || i >= (int)coins.size()) return -1;
        int take = helper(i, remaining - coins[i], coins);
        if (take != -1) take += 1;   
        int skip = helper(i + 1, remaining, coins);
        if (take == -1 && skip == -1) return -1;
        if (take == -1) return skip;
        if (skip == -1) return take;
        return min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        return helper(0, amount, coins);
    }
};
int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout<<sol.coinChange(coins, amount) << endl;
    return 0;
}
