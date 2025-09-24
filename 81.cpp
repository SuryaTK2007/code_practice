#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return true;

            // Handle duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            else if (nums[low] <= nums[mid]) { // Left half sorted
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            else { // Right half sorted
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 0, 1, 1, 1};
    int target = 0;

    if (sol.search(nums, target))
        cout << "Target " << target << " found in array.\n";
    else
        cout << "Target " << target << " not found in array.\n";

    return 0;
}
