class Solution {
public:
    int solve(int i,int j,vector<vector<int>>dp){

        if(i==0 && j==0){
            return 1;
        }

        if(i<0 || j< 0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=solve(i-1,j,dp);
        int b=solve(i,j-1,dp);

        return dp[i][j]= a+b;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,dp);
    }
};
