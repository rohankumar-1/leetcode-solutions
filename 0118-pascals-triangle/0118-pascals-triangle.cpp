class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        // set first row
        res.push_back({1});
        if(numRows == 1) return res;
        res.push_back({1, 1});
        
        for(int r = 2; r < numRows; r++){
            vector<int> curr;
            curr.push_back(1);  // first value
            
            for(int i = 0; i < res[r-1].size()-1; i++){
                curr.push_back(res[r-1][i] + res[r-1][i+1]);
            }
            
            curr.push_back(1);  // last value
            res.push_back(curr);
        }
        
        return res;
    }
};