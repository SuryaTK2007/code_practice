#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            long long min1 = (long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
            if (min1 > target) break;              
            long long max1 = (long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
            if (max1 < target) continue;           
            for (int j = i+1; j < n - 2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                long long min2 = (long long)nums[i] + nums[j] + nums[j+1] + nums[j+2];
                if (min2 > target) break;           
                long long max2 = (long long)nums[i] + nums[j] + nums[n-1] + nums[n-2];
                if (max2 < target) continue;      
                int l = j+1, r = n-1;
                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) ++l;
                    else if (sum > target) --r;
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1]) ++l;
                        while (l < r && nums[r] == nums[r-1]) --r;
                        ++l; --r;
                    }
                }
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> arr1 = {0, 0, 2, 1, 1};
    int target1 = 3;
    auto ans1 = sol.fourSum(arr1, target1);
    for (auto &q : ans1) {
        cout << "[";
        for (int i = 0; i < q.size(); i++) {
            cout << q[i] << (i+1 < q.size() ? ", " : "");
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
