#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, vector<int>& nums, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            helper(i + 1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> res = s.permute(nums);
    for (auto& v : res) {
        for (auto x : v) cout << x << " ";
        cout << "\n";
    }
}
