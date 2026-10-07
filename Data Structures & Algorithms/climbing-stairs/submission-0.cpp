class Solution {
public:
    int solve(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

        if(n==2){
            return 2;
        }


        int a=solve(n-1);
        int b=solve(n-2);

        return a+b;

    }
    int climbStairs(int n) {
        return solve(n);
    }
};
