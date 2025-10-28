#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        vector<int>lastSeen(128,-1);
        int n=s.size();
        int left=0;
        int maxlen=0;
        for(int right=0; right<n; right++){
            char ch=s[right];
            if(lastSeen[ch]!=-1){
                left=max(left, lastSeen[ch]+1);
            }
            lastSeen[ch]=right;
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int result = sol.longestUniqueSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
