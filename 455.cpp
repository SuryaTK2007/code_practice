#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0, i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                // cookie satisfies child
                count++;
                i++;
                j++;
            } else {
                // cookie too small, try next bigger one
                j++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << "Output 1: " << sol.findContentChildren(g1, s1) << endl; // Expected 1

    // Example 2
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << "Output 2: " << sol.findContentChildren(g2, s2) << endl; // Expected 2

    // Extra Testcase
    vector<int> g3 = {5, 10, 15};
    vector<int> s3 = {3, 6, 9, 20};
    cout << "Output 3: " << sol.findContentChildren(g3, s3) << endl; // Expected 2

    return 0;
}
