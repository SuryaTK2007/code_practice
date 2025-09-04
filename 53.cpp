#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];   
        int sum = nums[0];   
        for (int i = 1; i < n; i++) {
            sum = max(nums[i], nums[i] + sum);
            res = max(res, sum);              
        }
        return res;
    }
};
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    int result = sol.maxSubArray(nums);
    cout << "Maximum subarray sum = " << result << endl;
    return 0;
}
