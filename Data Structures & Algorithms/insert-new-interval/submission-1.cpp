class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if (intervals.empty()) {
            ans.push_back(newInterval);
            return ans;
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<int> temp = intervals[0];

        for (const auto& it : intervals) {
            if (it[0] <= temp[1]) {
                temp[1] = max(temp[1], it[1]);
            } else {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);

        return ans;
    }
};
