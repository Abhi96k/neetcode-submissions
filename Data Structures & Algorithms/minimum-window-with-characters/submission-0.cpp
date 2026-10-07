class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();

        int startIndex=-1;
        int minLen=1e9;
        int l=0;
        int r=0;
        int count=0;

        unordered_map<char,int>mp;

        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }

        while(r<n){
            if(mp[s[r]]>0){
                count++;
            }
            mp[s[r]]--;

            while(count==m){
                if(minLen>(r-l+1)){
                    minLen=(r-l+1);
                    startIndex=l;
                }
                mp[s[l]]++;

                if(mp[s[l]]>0){
                    count--;
                }
                l++;
            }
            r++;
        }

        if(startIndex==-1){
            return "";
        }

        return s.substr(startIndex,minLen);
    }
};
