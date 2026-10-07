class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int temp=numbers[low]+numbers[high];

            if(temp>target){
                high--;
            }
            else if(temp<target){
                low++;
            }
            else if(temp==target){
                return {low+1,high+1};
            }
        }

        return {-1,-1};
    }
};
