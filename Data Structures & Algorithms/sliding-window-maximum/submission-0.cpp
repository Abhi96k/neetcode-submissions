class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int>q;

        int l=0;
        int r=0;
        int n=nums.size();

        vector<int>ans(n-k+1);

        while(r<n){

            while(!q.empty() && nums[q.back()] <nums[r] ){
                q.pop_back();  
            }

            q.push_back(r);

            if(l>q.front()){
                q.pop_front();
            }

            if(r+1>=k){
                ans[l]=nums[q.front()];
                l++;
            }
            r++;
        }
        return ans;
    }
};
