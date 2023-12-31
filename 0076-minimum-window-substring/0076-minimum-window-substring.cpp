class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> curr;
        // find char occurences of t, fill into map
        for(auto c : t){
            mp[c]++;
        }
        
        int count = 0; int start = 0; 
        int ans_l = -1;
        int minLength = INT_MAX;
        
        for(int i = 0; i < s.length(); i++){
            // add current character to hash
            curr[s[i]]++;
            
            // if s[i] is a character currently needed to fulfill reqs, add to count
            if(curr[s[i]] <= mp[s[i]]){
                count++;
            }
            
            // if we have enough chars to fulfill entire t, check to see if we can shorten
            if(count == t.length()){
                
                // keep moving up left pointer until no longer fulfilling
                while(curr[s[start]] > mp[s[start]]){
                    curr[s[start]]--;
                    start++;
                }
                
                // if length of this window is minimum, set new, update answer
                if(minLength > i-start+1){
                    minLength = i-start+1;
                    ans_l = start;
                }
            }
        }
        
        if(ans_l == -1) return "";
        
        return s.substr(ans_l, minLength);
    }
};