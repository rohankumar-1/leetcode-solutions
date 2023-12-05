class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        
        // base cases
        dp[0] = cost[0];
        if(cost.size() == 1) return dp[0];
        dp[1] = cost[1];
        
        // tabulation
        for(int i = 2; i <= cost.size(); i++){
            dp[i] = min(dp[i-1], dp[i-2]);
            if(i != cost.size()){
                dp[i] += cost[i];
            }
        }
        
        return dp[cost.size()];
    }
};