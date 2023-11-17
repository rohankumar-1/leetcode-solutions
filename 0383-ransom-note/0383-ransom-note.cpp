class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto c : ransomNote){
            mp[c]++;
        }
        
        for(auto m : magazine){
            mp[m]--;
        }
        
        for(auto k : mp){
            if(k.second > 0){
                return false;
            }
        }
        
        return true;
    }
};