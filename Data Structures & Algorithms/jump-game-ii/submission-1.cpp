class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int jump=0;

        while(r<n-1){
            int maxrange=0;

            for(int i=l;i<=r;i++){
                maxrange=max(maxrange,i+nums[i]);
            }
            jump++;
            l=r+1;
            r=maxrange;
        }

        return jump;
    }
};
