class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        
        // record rows
        for(int i = 0; i < grid.size(); i++){
            mp[grid[i]]++;
        }
        
        int num = 0;
        for(int i = 0; i < grid.size(); i++){
            vector<int> col;
            
            for(int j = 0; j < grid.size(); j++){
                cout << grid[j][i] << endl;
                col.push_back(grid[j][i]);
            }
            
            if(mp.count(col) > 0){
                num += mp[col];
            }
        }
        
        return num;
    }
};