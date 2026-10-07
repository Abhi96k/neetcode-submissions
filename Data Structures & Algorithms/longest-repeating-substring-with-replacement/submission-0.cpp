class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.size();
        int l=0;
        int r=0;
        int maxfreq=0;
        int maxlenght=0;
        while(r<n){
            mp[s[r]]++;

            maxfreq=max(maxfreq,mp[s[r]]);

            if((r-l+1)-maxfreq>k){
                mp[s[l]]--;
                l++;
            }

            maxlenght=max(maxlenght,r-l+1);

            r++;

        }

        return maxlenght;
    }
};
