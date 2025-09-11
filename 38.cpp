#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string str = "1";   
        if (n == 1) return str;

        for (int i = 1; i < n; i++) {
            string res = "";
            for (int j = 0; j < str.size(); j++) {
                int count = 1;
                while (j + 1 < str.size() && str[j] == str[j+1]) {
                    count++;
                    j++;
                }
                res += to_string(count);
                res += str[j];
            }
            str = res;  
        }
        return str;
    }
};
int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "The " << n << "-th term of Count and Say sequence is: " 
         << sol.countAndSay(n) << endl;
    return 0;
}
