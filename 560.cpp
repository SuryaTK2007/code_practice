#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            if (freq.count(sum - k)) {
                count += freq[sum - k];
            }
            freq[sum]++;
        }
        return count;
    }
};
int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    cout << "Output 1: " << sol.subarraySum(nums1, k1) << endl; // Expected 2

    // Example 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    cout << "Output 2: " << sol.subarraySum(nums2, k2) << endl; // Expected 2 ([1,2], [3])

    // Extra Test
    vector<int> nums3 = {3, 4, 7, 2, -3, 1, 4, 2};
    int k3 = 7;
    cout << "Output 3: " << sol.subarraySum(nums3, k3) << endl; // Expected 4

    return 0;
}
