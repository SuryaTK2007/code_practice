#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string dir = "URLD";
    int dr[4] = {-1, 0, 0, 1};
    int dc[4] = {0, 1, -1, 0};

    bool isSafe(int r, int c, vector<vector<int>>& maze, int n) {
        return r >= 0 && c >= 0 && r < n && c < n && maze[r][c];
    }

    void findPath(int r, int c, vector<vector<int>>& maze, vector<string>& res, string& path) {
        int n = maze.size();
        if (r == n - 1 && c == n - 1) {
            res.push_back(path);
            return;
        }

        maze[r][c] = 0; // mark visited

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (isSafe(nr, nc, maze, n)) {
                path.push_back(dir[i]);
                findPath(nr, nc, maze, res, path);
                path.pop_back(); // backtrack
            }
        }

        maze[r][c] = 1; // unmark visited
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        string path = "";
        vector<string> res;
        if (maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
            findPath(0, 0, maze, res, path);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    int n;
    cout << "Enter maze size (n x n): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter maze (0 = blocked, 1 = open):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    Solution obj;
    vector<string> paths = obj.ratInMaze(maze);

    if (paths.empty()) {
        cout << "No path found.\n";
    } else {
        cout << "Possible paths:\n";
        for (auto &p : paths) cout << p << " ";
        cout << endl;
    }

    return 0;
}
