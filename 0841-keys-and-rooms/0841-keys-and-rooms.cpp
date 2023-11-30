class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> visited;
        
        q.push(0);
        
        while(!q.empty()){
            int room = q.front(); q.pop();
            
            for(auto i : rooms[room]){
                if(visited.count(i)==0){
                    q.push(i);
                }
            }
            
            visited.insert(room);
        }
        
        return visited.size()==rooms.size();
    }
};