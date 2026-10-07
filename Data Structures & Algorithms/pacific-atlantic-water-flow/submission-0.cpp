class Solution {
public:

    void dfs(vector<vector<int>>& heights,vector<vector<int>>&visited,int row,int col)
    {
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};

        visited[row][col] = 1;
        
        int n = heights.size();
        int m = heights[0].size();

        for(int i = 0;i<4;i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
            && visited[newRow][newCol] != 1 && heights[newRow][newCol] >= heights[row][col])
            {
                dfs(heights,visited,newRow,newCol);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            if (pacific[0][i] == 0) {
                dfs(heights, pacific, 0, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (pacific[i][0] == 0) {
                dfs(heights, pacific, i, 0);
            }
        }

        for (int i = 0; i < m; i++) {
            if (atlantic[n-1][i] == 0) {
                dfs(heights, atlantic, n-1, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (atlantic[i][m-1] == 0) {
                dfs(heights, atlantic, i, m-1);
            }
        }
        vector<vector<int>>ans;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};