#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        //int smaller_left=0, larger_right=0;
        int smaller_left_count=0;
        int greater_right_count=0;
        int greater_left_count=0;
        int smaller_right_count=0;
        int count=0;
        for(int i=0; i<n; i++){
            int mid=rating[i];
            smaller_left_count=0;
            greater_right_count=0;
            greater_left_count=0;
            smaller_right_count=0;
            for(int j=0; j<i; j++){
                if(rating[j]<mid) smaller_left_count++;
                if(rating[j]>mid) greater_left_count++;
            }
            for(int k=i+1; k<n; k++){
                if(rating[k]>mid) greater_right_count++;
                if(rating[k]<mid) smaller_right_count++;
            }
            count+=smaller_left_count*greater_right_count;
            count+=greater_left_count*smaller_right_count;
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<int> rating = {2,5,3,4,1};
    int result = sol.numTeams(rating);
    cout << "Number of teams: " << result << endl;
    return 0;
}
