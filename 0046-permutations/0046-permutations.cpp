class Solution {
    public:
        vector<vector<int>> res;

        void backtrack(int len, vector<int>& nums, vector<int>& curr){
            if(curr.size() == len){
                res.push_back(curr);
                return;
            }
            else{
                for(int i = 0; i < nums.size(); i++){
                    if(find(curr.begin(), curr.end(), nums[i]) == curr.end()){
                        curr.push_back(nums[i]);
                        backtrack(len, nums, curr);
                        curr.erase(curr.end()-1);
                    }
                }
            }

        }

        vector<vector<int>> permute(vector<int>& nums){
            vector<int> curr;
            backtrack(nums.size(), nums, curr);
            return res;
        }
};