#include<bits/stdc++.h>
using namespace std;
void helper(vector<int>& coins, int amount, int idx,
            int sum, vector<vector<int>>& res, vector<int>& temp){
    if(sum == amount){
        res.push_back(temp);
        return;
    }
    if(sum > amount) return;
    for(int i = idx; i < coins.size(); i++){
        temp.push_back(coins[i]);
        helper(coins, amount, i, sum + coins[i], res, temp);
        temp.pop_back(); 
    }
}

vector<vector<int>> coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> res;
    vector<int> temp;
    helper(coins, amount, 0, 0, res, temp);
    return res;
}

int main(){
    vector<int> coins;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        coins.push_back(x);
    }
    int amount;
    cin >> amount;
    vector<vector<int>> ans = coinChange(coins, amount);
    for(auto &vec : ans){
        for(auto x : vec){
            cout << x << " ";
        }
        cout << endl;
    }
}