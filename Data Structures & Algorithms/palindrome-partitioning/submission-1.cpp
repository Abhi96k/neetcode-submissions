class Solution {
public:
    bool ispaildron(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int index,string &s,vector<string>&temp,vector<vector<string>>&ans){
        if(index>=s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(ispaildron(s,index,i)==true){
                //doubt
                temp.push_back(s.substr(index,i+1-index));
                solve(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,temp,ans);
        return ans;
    }
};
