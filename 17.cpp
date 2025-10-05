#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    void backtrack(const string& digits, int i, string& path, vector<string>& res, const vector<string>& phone) {
        if (i == digits.size()) {
            res.push_back(path);
            return;
        }
        char digit = digits[i];
        if (digit == '0' || digit == '1') {
            backtrack(digits, i + 1, path, res, phone);
            return;
        }
        string letters = phone[digit - '0'];
        for (char ch : letters) {
            path.push_back(ch);
            backtrack(digits, i + 1, path, res, phone);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        backtrack(digits, 0, path, res, phone);
        return res;
    }
};

int main() {
    Solution sol;
    string digits = "23";
    vector<string> result = sol.letterCombinations(digits);

    cout << "Combinations for \"" << digits << "\": ";
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
