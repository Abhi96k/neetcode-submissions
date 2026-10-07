class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int a = nums[index] + solve(index + 2, nums, dp);
        int b = solve(index + 1, nums, dp);

        return dp[index] = max(a, b);
    }
    
    int rob(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> withoutfirst(nums.begin() + 1, nums.end());
        vector<int> withoutlast(nums.begin(), nums.end() - 1);

        vector<int> dp1(withoutfirst.size(), -1);
        int ans1 = solve(0, withoutfirst, dp1);

        vector<int> dp2(withoutlast.size(), -1);
        int ans2 = solve(0, withoutlast, dp2);

        return max(ans1, ans2);
    }
};
