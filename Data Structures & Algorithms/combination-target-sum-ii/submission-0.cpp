class Solution {
public:
    void solve(int index, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target){
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        
        if (index >= candidates.size() || target < 0) {
            return;
        }
        
        for (int i = index; i < candidates.size(); ++i) {
          
            if (i > index && candidates[i] == candidates[i - 1]){
                continue;
            }

            temp.push_back(candidates[i]);
            solve(i + 1, candidates, temp, ans, target - candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, temp, ans, target);
        return ans;
    }
};
