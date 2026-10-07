class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr_sum=nums[0];
        int maxi=nums[0];

        for(int i=1;i<n;i++){
            // curr_sum+=nums[i];

            // if(curr_sum<0){
            //     curr_sum=0;
            // }

            // if(curr_sum>maxi){
            //     maxi=curr_sum;
            // }

            curr_sum=max(curr_sum+nums[i],nums[i]);
            maxi=max(maxi,curr_sum);
        }
        return maxi;
    }
};
