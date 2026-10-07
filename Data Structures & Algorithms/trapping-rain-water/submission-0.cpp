class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int low=0;
        int high=n-1;
        int leftmax=height[low];
        int rightmax=height[high];
        int res=0;
        while(low<high){
            if(leftmax<rightmax){
                res+=leftmax-height[low];
                low++;
                leftmax=max(leftmax,height[low]);
                
            }
            else{
                res+=rightmax-height[high];
                high--;
                rightmax=max(rightmax,height[high]);
                
            }
        }

        return res;
    }
};
