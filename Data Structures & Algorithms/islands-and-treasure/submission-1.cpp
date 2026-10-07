#include <vector>
#include <queue>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return;
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        int drx[4] = {-1, 1, 0, 0};
        int dry[4] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int newR = row + drx[i];
                int newC = col + dry[i];
                
                if (newR < 0 || newR >= n || newC < 0 || newC >= m || grid[newR][newC] != INT_MAX) {
                    continue;
                }
                
                grid[newR][newC] = 1 + grid[row][col];
                q.push({newR, newC});
            }
        }
    }
};
