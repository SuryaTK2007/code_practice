// C++ program to generate all subsequences of a string
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to generate all subsequences
    void helper(string &s, int i, string temp, vector<string>& x) {
        if (i == s.size()) {
            x.push_back(temp);
            return;
        }

        // Exclude current character
        helper(s, i + 1, temp, x);

        // Include current character
        temp.push_back(s[i]);
        helper(s, i + 1, temp, x);
    }

    // Main function to return all subsequences
    vector<string> AllPossibleStrings(string s) {
        vector<string> x;
        string temp = "";
        helper(s, 0, temp, x);
        sort(x.begin(), x.end());
        return x;
    }
};

int main() {
    Solution sol;

    // Test example
    string s = "abc";
    vector<string> subsequences = sol.AllPossibleStrings(s);

    cout << "All subsequences of \"" << s << "\":" << endl;
    for (const string &sub : subsequences) {
        if(sub.empty())
            cout << "\"\""; // represent empty subsequence
        else
            cout << sub;
        cout << endl;
    }

    return 0;
}
