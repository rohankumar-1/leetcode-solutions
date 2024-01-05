class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        
        for(auto c : s1){
            mp[c]++;
        }
        
        // sliding window through s2
        for(int i = 0; i < s2.size(); i++){
            mp[s2[i]]--;
            
            if(i >= s1.size()){
                mp[s2[i-s1.size()]]++;
            }
            
            bool valid = true;
            for(auto k : mp){
                if(k.second != 0){
                    valid = false;
                }
            }
            
            if(valid) return true;
        }
        
        return false;
    }
};