class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Sort s1
        sort(s1.begin(), s1.end());
        int k = s1.size();
        int n = s2.size();

        for (int i = 0; i <= n - k; i++) {
            string temp = s2.substr(i, k);
            // Sort the substring temp
            sort(temp.begin(), temp.end());
            // Compare sorted s1 and sorted temp
            if (temp == s1) {
                return true;
            }
        }

        return false;
    }
};
