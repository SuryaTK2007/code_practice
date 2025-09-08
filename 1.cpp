#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index; 
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (index.find(complement) != index.end()) {
                return {index[complement], i};
            }
            index[nums[i]] = i;
        }
        return {}; 
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] 
             << " = " << target << endl;
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}
