class Solution {
public:
    int solve(int index,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy==1){
            int take=-prices[index]+solve(index+1,0,prices,dp);
            int notake=solve(index+1,1,prices,dp);

            profit=max(take,notake);
        }
        if(buy==0){
            int take=prices[index]+solve(index+2,1,prices,dp);
            int notake=solve(index+1,0,prices,dp);

            profit=max(take,notake);
        }

        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
