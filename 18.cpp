#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> res;
        if (n < 4) return res;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && arr[i] == arr[i-1]) continue; 
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i+1 && arr[j] == arr[j-1]) continue; 
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long sum = (long long)arr[i] + arr[j] + arr[l] + arr[r];

                    if (sum < target) {
                        l++;
                    } 
                    else if (sum > target) {
                        r--;
                    } 
                    else {
                        res.push_back({arr[i], arr[j], arr[l], arr[r]});
                        while (l < r && arr[l] == arr[l+1]) l++; 
                        while (l < r && arr[r] == arr[r-1]) r--;
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {0, 0, 2, 1, 1};
    int target1 = 3;
    auto ans1 = sol.fourSum(arr1, target1);
    for (auto &q : ans1) {
        cout << "[";
        for (int i = 0; i < q.size(); i++) {
            cout << q[i] << (i+1 < q.size() ? ", " : "");
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
