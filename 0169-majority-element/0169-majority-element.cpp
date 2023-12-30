class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto n : nums){
            mp[n]++;
            if(mp[n] > nums.size()/2) return n;
        }
        
        return -1;
    }
};