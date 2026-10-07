class Solution {
public:
    int solve(int index,string &s,set<string>&st,vector<int>&dp){
        if(index==s.size()){
            return 1;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        string temp="";
        for(int i=index;i<s.size();i++){
            temp+=s[i];

            if(st.find(temp)!=st.end()){
                if(solve(i+1,s,st,dp)==1){
                    return dp[i]=1;
                }
            }
        }

        return dp[index]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto it: wordDict){
            st.insert(it);
        }
        int n=s.size();
        vector<int>dp(n+1,-1);

        return solve(0,s,st,dp);
    }
};
