#include <bits/stdc++.h>
using namespace std;
int* greaterElement(int arr[], int n) {
    int* res = new int[n]; 
    for (int i = 0; i < n; i++) {
        int great = INT_MAX;
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[i]) {
                great = min(great, arr[j]);
                flag = true;
            }
        }
        if (flag) res[i] = great;
        else res[i] = -10000000; 
    }
    return res;
}
int main() {
    int arr[] = {4, 1, 3, 5};
    int n = 4;
    int* ans = greaterElement(arr, n);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    delete[] ans;  
    return 0;
}

/*
Given an array A of N length. We need to calculate the next smallest greater element for each element in a given array. If the next greater element is not a
vailable in a given array then we need to fill -10000000 at that index place.

Example 1:

Input : arr[] = {13, 6, 7, 12}
Output : _ 7 12 13 

Explanation:
Here, at index 0, 13 is the greatest value 
in given array and no other array element 
is greater from 13. So at index 0 we fill 
'-10000000'.

*/