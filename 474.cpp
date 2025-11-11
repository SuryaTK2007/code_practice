#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<string>& strs, int m, int n, int step, int count) {
        if (step == strs.size()) return count;
        int zcount = 0, ocount = 0;
        for (char ch : strs[step]) {
            if (ch == '0') zcount++;
            else ocount++;
        }
        int skip = helper(strs, m, n, step + 1, count);
        int take = 0;
        if (m >= zcount && n >= ocount)
            take = helper(strs, m - zcount, n - ocount, step + 1, count + 1);
        return max(skip, take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return helper(strs, m, n, 0, 0);
    }
};

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    Solution s;
    cout << s.findMaxForm(strs, m, n);
}
