#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> arr;
        string x;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr.push_back(x);
        }
        for (int i = 0; i < n; i++){
            string s = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                string temp = arr[j];
                if(s[0]!=temp[0] && s[1]==temp[1])
                    count++;
                if(s[1]!=temp[1] && s[0]==temp[0])
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}