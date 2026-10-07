class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) {
            return s;
        }

        int n = s.size();
        int maxLen = 0;
        int start = 0;

        // Handle even length palindromes
        for (int i = 0; i < n - 1; i++) {
            int left = i;
            int right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            if (maxLen < right - left - 1) {
                maxLen = right - left - 1;
                start = left + 1;
            }
        }

        // Handle odd length palindromes
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            if (maxLen < right - left - 1) {
                maxLen = right - left - 1;
                start = left + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};
