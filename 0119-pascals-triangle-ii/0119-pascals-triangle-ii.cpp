class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(2);

        ans[0].push_back(1);
        
        for(int i = 1; i <= rowIndex; i++){
            ans[1].push_back(1);    // initial 1 of the row

            for(int j = 1; j < i; j++){
                ans[1].push_back(ans[0][j-1] + ans[0][j]);
            }

            ans[1].push_back(1);

            ans[0] = ans[1];        // set ans[0] to contents of new row
            ans[1].clear();         // reset extra vector
        }

        return ans[0];
    }
};