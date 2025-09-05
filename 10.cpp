#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
private:
    bool helper(string &s, string &p, int i, int j) {
        if (j == p.size()) 
            return i == s.size();
        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < p.size() && p[j + 1] == '*') {
            return helper(s, p, i, j + 2) || (first_match && helper(s, p, i + 1, j));
        } else {
            return first_match && helper(s, p, i + 1, j + 1);
        }
    }
};
int main() {
    Solution sol;
    string s = "aab";
    string p = "c*a*b";  
    bool ans = sol.isMatch(s, p);
    cout << "s = " << s << "\n";
    cout << "p = " << p << "\n";
    cout << "Result: " << (ans ? "Match" : "No Match") << "\n";
    return 0;
}
