class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0;
        int j=0;

        int maxi=0;

        while(j<n){
            if(prices[j]>prices[i]){
                maxi=max(maxi,prices[j]-prices[i]);
            }
            else{
                i=j;
            }
            j++;
        }
        return maxi;
    }
};
