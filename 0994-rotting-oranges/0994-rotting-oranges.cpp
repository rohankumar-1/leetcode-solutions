class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = -1;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    // add all rotten oranges to queue
                    q.push({i, j});
                }
            }
        }
        
        res = max(0, bfs(grid, q));
        
        // check for any non-rotted oranges
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return res;
    }
    
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q){
        // starting at i, j, keep track of max depth
        int depth = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        // add stop to check depth
        q.push({INT_MAX, INT_MAX});
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; 
        
        // go through queue
        while(!q.empty()){
            // get new pair
            pair<int, int> p = q.front(); q.pop();
            
            // if INT_MAX, INT_MAX, we are at the next depth away from rotten orange
            if(p.first == INT_MAX){
                if(!q.empty()){
                    depth++;
                    q.push({INT_MAX, INT_MAX});
                    continue;
                }
                else{
                    break;
                }
            }
            
            for(auto d : dir){
                int i = p.first + d.first;
                int j = p.second + d.second;
                cout << i << ',' << j << endl;
                if(i < m && i >= 0 && j >= 0 && j < n){
                    if(grid[i][j] == 1){
                        grid[i][j] = 2;
                        q.push({i, j});
                    }
                }
            }
        }
        
        return depth;
    }
};