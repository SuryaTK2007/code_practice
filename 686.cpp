#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> helper(string pat, int n) {
        vector<int> lps(n, 0);
        int i = 1;
        int len = 0;
        while (i < n) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else i++;
            }
        }
        return lps;
    }

    bool kmp(string pat, string txt) {
        int n = txt.length();
        int m = pat.length();
        int i = 0, j = 0;
        vector<int> lps = helper(pat, m);
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
                if (j == m) return true;
            } else {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();
        string c = a;
        int rep = max(1, m / n);
        a = c;
        for (int i = 1; i < rep + 3; i++) {
            if (kmp(b, a)) return i;
            a += c;
        }
        return -1;
    }
};

int main() {
    Solution s;
    string a = "abcd";
    string b = "cdabcdab";
    cout << s.repeatedStringMatch(a, b);
}

/*
Logic Explanation:
1. The goal is to find the minimum number of times string 'a' must be repeated so that 'b' becomes a substring of it.
2. The helper() function builds the LPS array for KMP pattern matching.
3. The kmp() function searches pattern 'b' in text 'a' using the KMP algorithm.
4. The repeatedStringMatch() function:
   - Repeats 'a' enough times to cover the length of 'b'.
   - Tests if 'b' is a substring after repeating 'a' up to rep + 2 times (to handle overlap cases).
   - Returns the minimum number of repetitions needed or -1 if impossible.
*/
