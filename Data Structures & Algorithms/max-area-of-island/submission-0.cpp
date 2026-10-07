class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
       
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited[i][j] == 1) {
            return false;
        }
        return true;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, int& count, vector<vector<int>>& visited) {
        count++;
        visited[i][j] = 1;

        if (isValid(i - 1, j, grid, visited)) {
            dfs(i - 1, j, grid, count, visited);
        }
        if (isValid(i, j + 1, grid, visited)) {
            dfs(i, j + 1, grid, count, visited);
        }
        if (isValid(i, j - 1, grid, visited)) {
            dfs(i, j - 1, grid, count, visited);
        }
        if (isValid(i + 1, j, grid, visited)) {
            dfs(i + 1, j, grid, count, visited);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int count = 0;
                    dfs(i, j, grid, count, visited);
                    maxCount = max(maxCount, count);
                }
            }
        }

        return maxCount;
    }
};
