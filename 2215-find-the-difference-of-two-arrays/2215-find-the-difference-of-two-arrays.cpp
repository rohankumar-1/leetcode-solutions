class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        res.push_back({});
        res.push_back({});

        unordered_set<int> diff1;
        unordered_set<int> diff2;

        for(auto n1: nums1){
            diff1.insert(n1);
        }

        for(auto n2: nums2){
            diff1.erase(n2);
            diff2.insert(n2);
        }

        for(auto n1 : nums1){
            diff2.erase(n1);
        }

        for(auto i : diff1){
            res[0].push_back(i);
        }

        for(auto i : diff2){
            res[1].push_back(i);
        }

        return res;

    }
};