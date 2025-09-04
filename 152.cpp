#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) swap(currMax, currMin);
            currMax = max(nums[i], nums[i] * currMax);
            currMin = min(nums[i], nums[i] * currMin);
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};
int main() {
    vector<int> nums = {-2, 3, -4};
    Solution sol;
    int result = sol.maxProduct(nums);
    cout << "Maximum product subarray = " << result << endl;
    return 0;
}
