#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        map<char, string> phone_map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        string f_letter = phone_map.at(digits[0]);
        for (char ch : f_letter) {
            res.push_back(string(1, ch));
        }

        for (int i = 1; i < digits.size(); i++) {
            string curr = phone_map.at(digits[i]);
            vector<string> temp;
            for (string x : res) {
                for (char y : curr) {
                    temp.push_back(x + y);
                }
            }
            res = temp;
        }

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
