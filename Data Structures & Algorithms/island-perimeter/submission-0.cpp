class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int perimeter = 0;

        int directions[4][2] = {
            {-1, 0},  
            {1, 0},   
            {0, -1},  
            {0, 1}    
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 1) {

                    for (auto& dir : directions) {
                        int nr = i + dir[0];
                        int nc = j + dir[1];

                        if (nr < 0 || nr >= rows ||
                            nc < 0 || nc >= cols ||
                            grid[nr][nc] == 0) {
                            perimeter++;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};