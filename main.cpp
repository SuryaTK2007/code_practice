#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double helper(int i, vector<vector<int>>& classes, int extra){
        if(i == (int)classes.size()){
            double sum = 0.0;
            for(auto &c: classes){
                sum += (double)c[0] / c[1];
            }
            return sum / classes.size();
        }
        double best = 0.0;
        int p = classes[i][0], t = classes[i][1];
        for(int j = 0; j <= extra; j++){
            classes[i][0] = p + j;
            classes[i][1] = t + j;
            best = max(best, helper(i+1, classes, extra-j));
            classes[i][0] = p; // backtrack
            classes[i][1] = t;
        }
        return best;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        return helper(0, classes, extraStudents);
    }
};
int main() {
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;
    Solution sol;
    double ans = sol.maxAverageRatio(classes, extraStudents);
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}

/*

helper(0, extra=2)
│
├─ j=0 → helper(1,2)
│   ├─ j=0 → helper(2,2)
│   │   ├─ j=0 → helper(3,2) → 0.7000   (dist: 0,0,2)
│   │   ├─ j=1 → helper(3,1) → 0.7222   (dist: 0,1,1)
│   │   └─ j=2 → helper(3,0) → 0.7381   (dist: 0,2,0)
│   ├─ j=1 → helper(2,1)
│   │   ├─ j=0 → helper(3,1) → 0.7222   (dist: 0,1,1)
│   │   └─ j=1 → helper(3,0) → 0.7778   (dist: 1,1,0)
│   └─ j=2 → helper(2,0)
│       └─ j=0 → helper(3,0) → 0.7381   (dist: 0,2,0)
│
├─ j=1 → helper(1,1)
│   ├─ j=0 → helper(2,1)
│   │   ├─ j=0 → helper(3,1) → 0.7556   (dist: 1,0,1)
│   │   └─ j=1 → helper(3,0) → 0.7778   (dist: 1,1,0)
│   └─ j=1 → helper(2,0)
│       └─ j=0 → helper(3,0) → 0.7556   (dist: 1,0,1)
│
└─ j=2 → helper(1,0)
    └─ j=0 → helper(2,0)
        └─ j=0 → helper(3,0) → 0.7833   (dist: 2,0,0) 

*/