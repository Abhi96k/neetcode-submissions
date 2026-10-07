class Solution {
public:
    bool solve(int index,vector<int>&nums,vector<vector<int>>&dp,int target){
        if(index==nums.size()){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        int a=solve(index+1,nums,dp,target-nums[index]);
        int b=solve(index+1,nums,dp,target);

        return dp[index][target]=(a||b);
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(auto it:nums){
            target+=it;
        }
        if(target%2!=0){
            return false;
        }
        int n=nums.size();
        target=target/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        return solve(0,nums,dp,target);
    }
};
