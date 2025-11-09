#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool isSafe(int x, int y, int n, vector<vector<int>>& board) {
        return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
    }

    bool solve(int x, int y, int step, int n, vector<vector<int>>& board) {
        if (step == n * n) return true;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isSafe(nx, ny, n, board)) {
                board[nx][ny] = step;
                if (solve(nx, ny, step + 1, n, board)) return true;
                board[nx][ny] = -1;
            }
        }
        return false;
    }

    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0;
        if (solve(0, 0, 1, n, board))
            return board;
        return {};
    }
};

int main() {
    int n = 5;
    Solution sol;
    vector<vector<int>> result = sol.knightTour(n);
    if (result.empty()) {
        cout << "No solution exists for " << n << "x" << n << " board.\n";
    } else {
        cout << "Knight's Tour Path (" << n << "x" << n << "):\n";
        for (auto& row : result) {
            for (int cell : row)
                cout << setw(3) << cell << " ";
            cout << "\n";
        }
    }
    return 0;
}
