class Solution {
public:
    int solve(int index,vector<int>&nums,vector<int>&dp){
        if(index<0){
            return 0;
        }
        if(index==0){
            nums[0];
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int a=nums[index]+solve(index-2,nums,dp);
        int b=solve(index-1,nums,dp);

        return dp[index]=max(a,b);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int ind=n-1;
        vector<int>dp(n+1,-1);
        int c=solve(ind,nums,dp);
        return c;
    }
};
