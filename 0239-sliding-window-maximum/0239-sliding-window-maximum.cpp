class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // this vector will hold result
        vector<int> res;
        
        // iterate through each element in the array nums
        
        // queue holds current max at top
        priority_queue<int> pq;
        
        // map holds only current window
        unordered_map<int, int> mp;
        
        // top of queue should always be current max
        for(int i = 0; i < nums.size(); i++){
            // update map and queue
            mp[nums[i]]++;
            pq.push(nums[i]);
            if(i-k >= 0){
                mp[nums[i-k]]--;
            }
            
            // if we have enough values to start checking windows
            if(pq.size() >= k){
                
                // keep taking off queue while element is not in current window
                while(mp[pq.top()] == 0){
                    pq.pop();
                }
                
                // add top of pq (max) to res vector
                res.push_back(pq.top());
            }
        }
        
        return res;
    }
};