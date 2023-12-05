class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // build dp table
        vector<vector<int>> dp;
        for(int i = 0; i < triangle.size(); i++){
            dp.push_back(vector<int>(triangle[i].size(), 0));
        }
        
        /*
        tabulation:
        - dp[i][j] can either come from dp[i-1][j] or dp[i-1][j-1]
        - also need to add cost at dp[i][j]
        - return minimum value of last row of dp
        */
        
        // base case
        dp[0][0] = triangle[0][0];
        
        // iteration
        for(int i = 1; i < triangle.size(); i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(j == triangle[i].size()-1){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
            }
        }
        
        return *min_element(dp[triangle.size()-1].begin(), dp[triangle.size()-1].end());
    }
};