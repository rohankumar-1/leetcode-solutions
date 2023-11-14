class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(res, nums, curr, 0);
        return res;
    }   
    
    void solve(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr, int idx){
        if(idx == nums.size()){
            res.push_back(curr);
            return;
        }
        solve(res, nums, curr, idx+1);
        curr.push_back(nums[idx]);
        solve(res, nums, curr, idx+1);
        curr.pop_back();
        return;
    }
};