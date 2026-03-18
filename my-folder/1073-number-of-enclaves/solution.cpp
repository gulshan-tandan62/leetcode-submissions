class Solution {
    void bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
       
        grid[i][j] = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i].first;
                int nc = col + directions[i].second;
                if (nr >= 0 && nr < grid.size() && nc >= 0 &&
                    nc < grid[0].size() && grid[nr][nc] == 1) {

                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                bfs(i, 0, grid);
            }
            if (grid[i][m - 1] == 1) {
                bfs(i, m - 1, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                bfs(0, i, grid);
            }
            if (grid[n - 1][i] == 1) {
                bfs(n - 1, i, grid);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};
