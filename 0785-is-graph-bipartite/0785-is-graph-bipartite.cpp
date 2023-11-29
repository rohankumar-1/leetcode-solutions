class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> hm;
        queue<int> q;

        /* set 1 = 1, set 2 = 2 in hash map (this is 'color' of set)*/
        for(int i = 0; i < graph.size(); i++){
            if(hm[i]) continue;

            hm[i] = 1;
            q.push(i);
            while(!q.empty()){
                int curr = q.front(); q.pop();

                for(auto neigh : graph[curr]){
                    if(hm[neigh]){
                        // we have already visited neighbor, check for color
                        if(hm[neigh] == hm[curr]){
                            return false;
                        }
                    }
                    else{
                        if(hm[curr] == 1){
                            hm[neigh] = 2;
                        }
                        else{
                            hm[neigh] = 1;
                        }
                        q.push(neigh);
                    }
                }
            }
        }
        return true;
    }
};