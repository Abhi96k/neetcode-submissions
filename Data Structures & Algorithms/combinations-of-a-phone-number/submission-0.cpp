class Solution {
public:
    void solve(int index, string &digits, string &temp, vector<string> &ans, string mapping[]) {
        if (index >= digits.size()) {
            ans.push_back(temp);
            return;
        }
        string res = mapping[digits[index] - '0'];

        for (int i = 0; i < res.size(); i++) {
            temp.push_back(res[i]);
            solve(index + 1, digits, temp, ans, mapping);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if (digits.size() == 0) {
            return ans;
        }

        solve(0, digits, temp, ans, mapping);
        return ans;
    }
};
