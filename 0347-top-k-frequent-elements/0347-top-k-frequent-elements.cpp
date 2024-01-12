class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(auto n : nums){
            mp[n]++;
        }
        
        priority_queue<pair<int, int>> pq;
        
        for(auto p : mp){
            pq.push({p.second, p.first});
        }
        
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};