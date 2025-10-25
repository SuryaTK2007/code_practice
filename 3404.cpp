#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<double, long long> freq;
        long long ans = 0;

        for (int r = 4; r < (int)nums.size(); ++r) {
            // Build frequency table for ratios nums[p]/nums[q]
            for (int p = 0, q = r - 2; q - p > 1; ++p) {
                double ratio = (double)nums[p] / (double)nums[q];
                freq[ratio]++;
            }

            // Count subsequences matching ratio nums[s]/nums[r]
            for (int s = r + 2; s < (int)nums.size(); ++s) {
                double ratio = (double)nums[s] / (double)nums[r];
                ans += freq[ratio];
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example input
    vector<int> nums = {3, 4, 3, 4, 3, 4, 3, 4};

    Solution sol;
    long long result = sol.numberOfSubsequences(nums);

    cout << "Number of subsequences: " << result << "\n";
    return 0;
}
