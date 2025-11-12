#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());

        if (s.size() == 1 && s.count(1)) return 0;

        if (s.count(1)) {
            int non1 = 0;
            for (int x : nums) if (x != 1) non1++;
            return non1;
        }

        int g = nums[0];
        for (int i = 1; i < n; i++) g = gcd(g, nums[i]);
        if (g > 1) return -1;

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, (j - i) + (n - 1));
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    vector<int> nums = {935839,59074,1,1,1,539890,135036,248163,519664,794201,915143,353146,764742,1,1,1,33204,661690,1,1,414294,1,778895,1,1,357151,1,645007,707404,599671,1,120017,220478,69724,1,1,1,604942,543935,1,1};
    Solution s;
    cout << s.minOperations(nums);
}

/*
Logic Explanation:
1. If all numbers are already 1 → return 0.
2. If there is at least one 1 → each non-1 element can become 1 using one gcd operation with a neighboring 1, so answer = count of non-1 elements.
3. If the gcd of the entire array > 1 → impossible to get 1 → return -1.
4. Otherwise, find the shortest subarray whose gcd becomes 1; the first 1 requires (length - 1) operations, and spreading 1 to others takes (n - 1) more, so result = (j - i) + (n - 1).
*/
