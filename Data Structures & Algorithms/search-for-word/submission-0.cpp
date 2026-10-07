class Solution {
public:
    bool solve(int i,int j,int n,int m,vector<vector<char>>&board, string word,int index){
        if(index==word.size()){
            return true;
        }

        if(i<0 || j<0 ||i>=n || j>=m || board[i][j]!=word[index]){
            return false;
        }

        char ch=board[i][j];
        board[i][j]='#';

        bool a=solve(i+1,j,n,m,board,word,index+1);
        bool b=solve(i,j+1,n,m,board,word,index+1);
        bool c=solve(i-1,j,n,m,board,word,index+1);
        bool d=solve(i,j-1,n,m,board,word,index+1);

        board[i][j]=ch;

        return (a||b||c||d);

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,n,m,board,word,0)==true){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
