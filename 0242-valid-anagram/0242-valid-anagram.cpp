class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;

        // populate HashMap
        for(auto sx : s){ map[sx]++; }
    
        // decrement if found in t
        for(auto tx : t){ 
            map[tx]--; 
        }

        // check for all zeros
        for(auto m : map){
            if(m.second != 0){
                return false;
            }
        }

        // if every single value is 0, then s is an anagram of t 
        return true;
    }
};