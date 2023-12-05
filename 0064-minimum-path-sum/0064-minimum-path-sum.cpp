class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // get sizes of grid
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        /*
        tabulation:
        - dp[i][j] is the minimum sum to reach any of the slots around it + grid[i][j]
        - we can only move right and down (so only check left and up slots)
        - need to validate that left and up are valid moves
        */
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (i > 0 && j > 0) {
                    // we can check left and up
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                }
                else if (i > 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else if (j > 0) {
                    dp[i][j] = dp[i][j-1];
                }
                
                dp[i][j] += grid[i][j]; 
            }
        }
        
        
        // return bottom right corner
        return dp[m-1][n-1];
    }
};