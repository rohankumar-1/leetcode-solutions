class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        // result vector
        vector<vector<int>> res;
        
        // merge and add to result
        int i = 0;
        while(i < intervals.size()){
            // start at interval's beginning
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            // keep going through intervals until the end of the interval is less than the beginning of the next interval
            i++;
            while(i < intervals.size() && end >= intervals[i][0]){
                end = max(intervals[i][1], end);
                i++;
            }
            
            res.push_back({start, end});
        }
        
        
        return res;
    }
};