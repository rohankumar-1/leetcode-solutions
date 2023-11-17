class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // idea is to utilize sliding window, starting at s
        // we maintain a unordered_map of (char, idx) for the current substring
        // if then next char has not been seen yet, add to map
        // if the char has been seen, move left pointer to idx of first occurence of char+1
        int left = 0;
        int maxLen = 0;

        unordered_map<char, int> mp;
        for(int right = 0; right < s.length(); right++){
            if(!mp.count(s[right]) || mp[s[right]] < left){
            // we have not seen this character, or character has been seen before current substring
                mp[s[right]] = right;
                if(right-left+1 > maxLen){
                    maxLen = right-left+1;
                }
            }
            else{
            // we have seen this character before
                left = mp[s[right]] + 1;
                mp[s[right]] = right;
            }
        }

        return maxLen;
    }
};