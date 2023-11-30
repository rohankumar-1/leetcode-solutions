class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int prov = 0; int n = isConnected.size();
        queue<int> q;
        vector<int> vis(n, false);

        for(int i = 0; i < n; i++){
            if(vis[i]){ continue; }
            q.push(i);
            prov++;

            while(!q.empty()){
                int curr = q.front(); q.pop();

                for(int j = 0; j < n; j++){
                    if(isConnected[curr][j] && !vis[j]){
                        q.push(j);
                    }
                }
                vis[curr] = true;
            }
        }

        return prov;
    }
};