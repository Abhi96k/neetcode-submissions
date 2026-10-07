class Solution {
public:
    int solve(int index,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(amount<0){
            return 0;
        }  
        if(amount==0){
            return 1;
        }
        if(index>=coins.size()){
            return 0;
        }

        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }

        int take=solve(index,coins,amount-coins[index],dp);

        int notake=solve(index+1,coins,amount,dp);

        return dp[index][amount]=(take+notake);

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int index=0;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));

        return solve(index,coins,amount,dp);
    }
};
