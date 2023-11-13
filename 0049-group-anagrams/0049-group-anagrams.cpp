class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        /*
        iterate through strings, for each string, create the hashmap, compare to
        other hashmaps, if anagram, add to thay vector, else create new vector
        */
        
        for(auto str : strs){
            string t = str;
            sort(t.begin(), t.end());
            map[t].push_back(str);
        }

        for(auto m : map){
            res.push_back(m.second);
        }
        
        return res;
    }
};