#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        vector<int>pref(n);
        vector<int>suff(n);
        pref[0]=1, suff[n-1]=1;
        for(int i=1; i<n; i++){
            pref[i]=nums[i-1]*pref[i-1];
        }
        for(int i=n-2; i>=0; i--){
            suff[i]=suff[i+1]*nums[i+1];
        }
        for(int i=0; i<n; i++){
            res[i]=pref[i]*suff[i];
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    Solution sol;
    vector<int> ans = sol.productExceptSelf(nums);
    cout << "[";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if(i < ans.size()-1) cout << ",";
    }
    cout << "]";
    return 0;
}
/*
Prefix prod gives you the product before the element i and suffix prod gives you the product after the element i, so by combining both prefix and suffix
it will give a product which is the product of elements before and after i and that is what we need.
*/