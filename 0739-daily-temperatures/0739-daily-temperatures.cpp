class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res(temperatures.size(), 0);
        
        // push (idx, temp) pairs onto stack, but first, pop all that are less than it
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > st.top().second){
                res[st.top().first] = i-st.top().first;
                st.pop();
            }
            
            st.push({i, temperatures[i]});
        }
        
        return res;
    }
};