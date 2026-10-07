class Solution {
public:
    void solve(vector<string>&ans,string &temp,int open,int close){
        if(open==0 && close==0){
            ans.push_back(temp);
            return ;
        }

        if(open>0){
            temp.push_back('(');
            solve(ans,temp,open-1,close);
            temp.pop_back();
        }
        if(close>open){
            temp.push_back(')');
            solve(ans,temp,open,close-1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        int open=n;
        int close=n;
        vector<string>ans;
        solve(ans,temp,open,close);
        return ans;
    }
};
