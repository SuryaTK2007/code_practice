#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    bool can_partition(vector<int>& nums, int i) {
        int n = nums.size();
        bool res = false;
        if (i == n) return true; // base case
        if (dp[i] != -1) return dp[i]; // memoization
        // Case 1: two equal elements
        if (i + 1 < n && nums[i] == nums[i + 1]) {
            res = res || can_partition(nums, i + 2);
        }
        // Case 2: three equal elements
        if (i + 2 < n && nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
            res = res || can_partition(nums, i + 3);
        }
        // Case 3: three consecutive increasing elements
        if (i + 2 < n && nums[i] + 1 == nums[i + 1] && nums[i] + 2 == nums[i + 2]) {
            res = res || can_partition(nums, i + 3);
        }

        return dp[i] = res;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        return can_partition(nums, 0);
    }
};
int main() {
    Solution sol;
    // Example test case
    vector<int> nums = {1, 1, 1, 2, 3};
    if (sol.validPartition(nums)) {
        cout << "Valid partition exists ✅" << endl;
    } else {
        cout << "No valid partition ❌" << endl;
    }
    return 0;
}
