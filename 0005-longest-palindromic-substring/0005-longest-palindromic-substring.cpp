class Solution {
public:
    string longestPalindrome(string s) {
        int left, right;
        int currLen, maxLen = 0;

        string maxStr = "";

        // center around i, check for even palindrome and odd palindrome
        for(int i = 0; i < s.length(); i++){
            // odd palindrome
            currLen = 1;
            if(currLen > maxLen){
                maxLen = currLen;
                maxStr = s.substr(left, maxLen);
            }

            left = i-1; right = i+1;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                currLen += 2;
                if(currLen > maxLen){
                    maxLen = currLen;
                    maxStr = s.substr(left, maxLen);
                }
                left--; right++;
            }

            // even palindrome
            currLen = 0;
            left = i; right = i+1;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                currLen += 2;
                if(currLen > maxLen){
                    maxLen = currLen;
                    maxStr = s.substr(left, maxLen);
                }
                left--; right++;
            }
        }
        
        return maxStr;
    }
};