#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int sum = arr[l].first + arr[r].first;
            if (sum == target) {
                return {arr[l].second, arr[r].second}; 
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
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
