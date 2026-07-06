#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    vector<int> res;
    for (int i = 0; i < n-1; i++){
        if(abs(arr[i+1] - arr[i])==1){
            res.push_back(arr[i]);
        }
        else if(arr[i+1]>arr[i]){
            int x = arr[i + 1];
            int j = arr[i];
            while(j!=x){
                res.push_back(j);
                j++;
            }
        }
        else{
            int x = arr[i + 1];
            int j = arr[i];
            while(j!=x){
                res.push_back(j);
                j--;
            }
        }
    }
    res.push_back(arr[n - 1]);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}