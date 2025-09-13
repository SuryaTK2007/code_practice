#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int max_e = 0;
        int max_count = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count > max_count) {
                max_count = count;
                max_e = nums[i];
            }
        }
        return max_e;
    }
};
int main() {
    int n;
    cin >> n;  
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.majorityElement(nums) << endl;
    return 0;
}
