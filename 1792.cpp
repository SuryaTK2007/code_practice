#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double gain(int a, int b){
        return (double)(a+1)/(b+1)-(double)(a)/(b);
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double,int,int>>pq;
        for(auto& c: classes){
            pq.push({gain(c[0],c[1]),c[0],c[1]});
        }
        while(extraStudents){
            auto [g, p, t]=pq.top();
            pq.pop();
            p+=1, t+=1;
            pq.push({gain(p,t),p,t});
            extraStudents--;
        }
        double sum=0.0;
        while(!pq.empty()){
            auto [g,p,t]=pq.top();
            pq.pop();
            sum+=(double)(p)/(t);
        }
        return sum/classes.size();
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
Step 0: Initialization

Ratios initially:

Class A: 1/2 = 0.500
Class B: 3/5 = 0.600
Class C: 2/2 = 1.000

Δ (gain if we add 1 student):
A: (2/3 - 1/2) = 0.1667
B: (4/6 - 3/5) = 0.0667
C: (3/3 - 2/2) = 0.0000
Max-heap by Δ = [A=0.1667, B=0.0667, C=0.0000]
Extra students left = 2

Iteration 1

Pick class A (largest Δ=0.1667).
Assign 1 student → (1,2) → (2,3).
New ratio A = 2/3 = 0.667.
Recompute Δ for A: (3/4 - 2/3) = 0.0833.
Push back → Heap = [A=0.0833, B=0.0667, C=0.0000].
Extra left = 1.

Iteration 2

Pick class A again (largest Δ=0.0833).
Assign 1 student → (2,3) → (3,4).
New ratio A = 3/4 = 0.750.
Recompute Δ for A: (4/5 - 3/4) = 0.0500.
Push back → Heap = [B=0.0667, A=0.0500, C=0.0000].
Extra left = 0.

Final State

Ratios:
A = 3/4 = 0.750
B = 3/5 = 0.600
C = 2/2 = 1.000

Average = (0.750 + 0.600 + 1.000) / 3 = 0.78333
*/