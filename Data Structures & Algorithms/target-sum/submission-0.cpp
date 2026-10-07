class Solution {
public:
    int solve(int index,int n,int sum,int target,vector<int>&nums,
    vector<vector<int>>&dp){
        if(index==n){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[index][sum+1000]!=-1){
            return dp[index][sum+1000];
        }

        int add=solve(index+1,n,sum+nums[index],target,nums,dp);
        int sub=solve(index+1,n,sum-nums[index],target,nums,dp);

        return dp[index][sum+1000]=(add+sub);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        vector<vector<int>>dp(n+1,vector<int>(2001,-1));

        return solve(0,n,sum,target,nums,dp);
    }
};
