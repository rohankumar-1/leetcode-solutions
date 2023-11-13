class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ret;


        int goal;
        for(int i = 0; i < nums.size(); i++){
            goal = target - nums[i];
            unordered_map<int,int>::iterator loc = m.find(goal);
            if(loc == m.end()){
                // didn't find the goal value, add value to map
                m[nums[i]] = i;   // save pair as {val, index}
            }
            else{
                // we found the second value, so 
                ret.push_back(i);
                ret.push_back(loc->second);
                break;
            }
        }
        return ret;
    }
};