class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int low=i+1;
            int high=n-1;


             if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
             }            

            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];

                if(sum>0){
                    high--;
                }
                else if(sum<0){
                    low++;
                }
                else {
                    ans.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    high--;

                    while(low<high && nums[low]==nums[low-1]){
                        low++;
                    }
                }
            }
        }
        return ans;
    }
};
