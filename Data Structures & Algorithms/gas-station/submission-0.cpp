class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalDiff=0;
        int index=0;
        int fuel=0;


        for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            fuel+=diff;
            totalDiff+=diff;

            if(fuel<0){
                fuel=0;
                index=i+1;
            }
        }

        if(totalDiff<0){
            return -1;
        }

        return index;
    }
};
