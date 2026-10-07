class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;


        for (int it : nums) {
            mp[it]++;
        }

        // Buckets: index = frequency
        vector<vector<int>> bucket(n + 1);


        for (auto &it : mp) {
            bucket[it.second].push_back(it.first);
        }


        for (int i = n; i >= 0 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};
