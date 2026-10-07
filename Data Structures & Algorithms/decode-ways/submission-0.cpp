class Solution {
public:
    int solve(int index,string &s,vector<int>&dp){
        if(index==s.size()){
            return 1;
        }

        if(s[index]=='0'){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int count1=solve(index+1,s,dp);

        int count2=0;

        if(index<s.size()-1 && s.substr(index,2)<"27"){
            count2=solve(index+2,s,dp);
        }

        return dp[index]=(count1+count2);
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(0,s,dp);
    }
};
