class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n != m) {
            return false;
        }

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for (char c : s) {
            mp1[c]++;
        }

        for (char c : t) {
            mp2[c]++;
        }

        for (auto it : mp1) {
            char character = it.first;
            int frequency = it.second;

            if (mp2[character] != frequency) {
                return false;
            }
        }

        return true;
    }
};
