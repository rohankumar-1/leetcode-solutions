class Solution {
public:
    
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        // dynamic programming space
        int dp[n];
        
        // base cases
        dp[0] = 1;  // if 1 step left, 1 option
        dp[1] = 2;  // if 2 steps left, 2 options
        
        for(int i = 2; i < n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n-1];
    }


};