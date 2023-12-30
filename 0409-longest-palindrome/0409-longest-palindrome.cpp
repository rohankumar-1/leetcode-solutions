class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        
        // fill occurence map of characters in string
        for(auto c : s){
            mp[c]++;
        }
        
        // longest palindrome is # of even numbered occurences + an additional value if possible
        int length = 0;
        bool middleFound = false;
        
        for(auto p : mp){
            length += 2 * (p.second / 2) ;
            
            
            if(!middleFound && p.second%2 != 0){
                middleFound = true;
                length++;
            }
        }
        
        return length;
    }
};