class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        
        if(i>=0 && i<m && j>=0 && j<n && board[i][j] == 'O')
            return true;
        
        return false;
    }
    
    void DFS(int i, int j, vector<vector<char>>& board)
    {
        board[i][j] = 'B';
        if(isValid(i-1, j, board))
        {
            DFS(i-1, j, board);
        }
        if(isValid(i+1, j, board))
        {
            DFS(i+1, j, board);
        }
        if(isValid(i, j-1, board))
        {
            DFS(i, j-1, board);
        }
        if(isValid(i, j+1, board))
        {
            DFS(i, j+1, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; i++)
        {
            if(board[i][0] == 'O')
            {
                board[i][0] = 'B';
                DFS(i, 0, board);
            }
        }
        
        
        for(int i=0;i<m; i++)
        {
            if(board[i][n-1] == 'O')
            {
                board[i][n-1] = 'B';
                DFS(i, n-1, board);
            }
        }
        
        for(int j=0; j<n; j++)
        {
            if(board[0][j] == 'O')
            {
                board[0][j] = 'B';
                DFS(0, j, board);
            }
        }
        
        for(int j=0; j<n; j++)
        {
            if(board[m-1][j] == 'O')
            {
                board[m-1][j] = 'B';
                DFS(m-1, j, board);
            }
        }
        
        for(int i =0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'B'){
                    board[i][j] = 'O';
                }
            }
        }
    } 
};