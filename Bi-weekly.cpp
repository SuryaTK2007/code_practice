#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int maxLen = 0;
        int count = 2; // minimal length to start checking

        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i-1] + nums[i-2]) {
                count++;
            } else {
                count = 2; // reset
            }
            maxLen = max(maxLen, count);
        }

        return maxLen >= 3 ? maxLen : 0; // must be at least length 3
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<int> nums1 = {1, 2, 3, 5, 8, 13};
    vector<int> nums2 = {1, 3, 4, 7, 11, 18, 29};
    vector<int> nums3 = {1, 2, 4, 7, 11};

    cout << "Longest Fibonacci subarray length of nums1: " 
         << sol.longestSubarray(nums1) << endl;

    cout << "Longest Fibonacci subarray length of nums2: " 
         << sol.longestSubarray(nums2) << endl;

    cout << "Longest Fibonacci subarray length of nums3: " 
         << sol.longestSubarray(nums3) << endl;

    return 0;
}
