#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            if(ch=='(' || ch=='[' || ch=='{') {
                st.push(ch);
            } else {
                if(st.empty()) return false;
                if((ch==')' && st.top()=='(') ||
                   (ch==']' && st.top()=='[') ||
                   (ch=='}' && st.top()=='{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string with parentheses/brackets/braces: ";
    cin >> s;

    if(sol.isValid(s)) {
        cout << "Valid string ✅" << endl;
    } else {
        cout << "Invalid string ❌" << endl;
    }

    return 0;
}
