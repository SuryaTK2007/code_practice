#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int n = s.size();
        int left = 0;
        int maxlen = 0;

        for (int right = 0; right < n; right++) {
            // If duplicate found, shrink window from left
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }

            // Add new character
            seen.insert(s[right]);

            // Update max length
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
