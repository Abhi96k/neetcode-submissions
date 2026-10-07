class Solution {
public:
    void solve(int index,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int target){
        if(index>=nums.size()){
            return;
        }
        if(target<0){
            return ;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);

        solve(index,nums,temp,ans,target-nums[index]);

        temp.pop_back();

        solve(index+1,nums,temp,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums,temp,ans,target);
        return ans;
    }
};
