class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        
        // priority queue, sorted by distance float, second value is the actual point itself
        priority_queue<pair<long, vector<int>>, vector<pair<long, vector<int>>>, greater<pair<long, vector<int>>>> pq;
        
        // fill priority queue with k shortest distances
        for(auto p : points){
            pq.push(make_pair(dist(p), p));
        }
        
        // get top k distances
        while(k > 0){
            res.push_back(pq.top().second); pq.pop();
            k--;
        }
        
        return res;
    }
    
    long dist(vector<int>& p){
        return ((long long int) p[0])*p[0] + p[1]*p[1];
    }
};