class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        int curr_end=intervals[0][1];
        int ans=0;

        for(int i=1;i<n;i++){
            if(intervals[i][0]<curr_end){
                ans++;
                curr_end=min(curr_end,intervals[i][1]);
            }
            else{
                curr_end=intervals[i][1];
            }
        }
        return ans;
    }
};