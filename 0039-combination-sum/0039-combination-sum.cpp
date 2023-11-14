class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates, target, curr, 0);
        return res;    
    }

    void solve(vector<int>& candidates, int target, vector<int>& curr, int idx){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        else if(target < 0){
            return;
        }
        else{
            for(int i = idx; i < candidates.size(); i++){
                curr.push_back(candidates[i]);
                solve(candidates, target - candidates[i], curr, i);
                curr.pop_back();
            }
            return;
        }
    }

};