#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = arr[n - 1] - arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] - k < 0) continue;
            int smallest = min(arr[0] + k, arr[i] - k);             //The first part (0..i-1) gets +k.
            int greatest = max(arr[n - 1] - k, arr[i - 1] + k);     //The second part (i..n-1) gets -k.
            ans = min(ans, greatest - smallest);
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> arr1 = {1, 5, 8, 10};
    int k1 = 2;
    cout << sol.getMinDiff(arr1, k1) << endl;
    vector<int> arr2 = {3, 9, 12, 16, 20};
    int k2 = 3;
    cout << sol.getMinDiff(arr2, k2) << endl;
    return 0;
}
/*
Given an array arr[] denoting heights of n towers and a positive integer k.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by k
Decrease the height of the tower by k
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

Note: It is compulsory to increase or decrease the height by k for each tower. After the operation, the resultant array should not contain any negative integers.

Examples :

Input: k = 2, arr[] = [1, 5, 8, 10]
Output: 5
Explanation: The array can be modified as [1+k, 5-k, 8-k, 10-k] = [3, 3, 6, 8]. The difference between the largest and the smallest is 8-3 = 5.

Input: k = 3, arr[] = [3, 9, 12, 16, 20]
Output: 11
Explanation: The array can be modified as [3+k, 9+k, 12-k, 16-k, 20-k] = [6, 12, 9, 13, 17]. The difference between the largest and the smallest is 17-6 = 11. 

*/