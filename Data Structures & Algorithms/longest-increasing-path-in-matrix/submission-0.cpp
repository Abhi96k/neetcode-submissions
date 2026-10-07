class Solution {
public:
    int solve(int i, int j, int prev, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] <= prev) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = 1 + solve(i - 1, j, matrix[i][j], n, m, matrix, dp);
        int left = 1 + solve(i, j - 1, matrix[i][j], n, m, matrix, dp);
        int right = 1 + solve(i, j + 1, matrix[i][j], n, m, matrix, dp);
        int down = 1 + solve(i + 1, j, matrix[i][j], n, m, matrix, dp);

        return dp[i][j] = max({up, left, right, down});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = 0;

        int prev=-1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxi = max(maxi, solve(i, j, prev, n, m, matrix, dp));
            }
        }

        return maxi;
    }
};
