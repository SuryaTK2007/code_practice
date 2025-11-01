#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = 0;
        for (int num : nums) {
            num %= k;
            for (int i = 0; i < k; i++) {
                dp[i][num] = dp[num][i] + 1;
                res = max(res, dp[i][num]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> nums = {1, 2, 1, 2};
    int k = 3;

    int result = sol.maximumLength(nums, k);
    cout << "Maximum subsequence length: " << result << endl;

    return 0;
}
