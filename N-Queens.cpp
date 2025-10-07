#include <iostream>
#include <vector>
using namespace std;

int isSafe(vector<vector<int>>& mat, 
                    int row, int col) {
    int n = mat.size();
    int i, j;
    for (i = 0; i < row; i++)
        if (mat[i][col])
            return 0;
    for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j])
            return 0;
    for (i = row-1, j = col+1; j < n && i >= 0; i--, j++)
        if (mat[i][j])
            return 0;

    return 1;
}
void placeQueens(int row, vector<vector<int>>& mat, vector<vector<int>>&result) {
    int n = mat.size();
    if(row == n) {
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    ans.push_back(j + 1);
                }
            }
        }
        result.push_back(ans);
        return;
    }
    for(int i = 0; i < n; i++){
        if(isSafe(mat, row, i)){
            mat[row][i] = 1;
            placeQueens(row + 1, mat, result);
            mat[row][i] = 0; 
        }
    }
}
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> result;
    placeQueens(0, mat, result);
    return result;
}

int main() {
    int n = 4;
    vector<vector<int>> result = nQueen(n);
    for(auto &ans : result){
        for(auto i: ans){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}