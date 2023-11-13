class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);     // convert to a string
        
        int i = 0; int j = s.length()-1;
        while(i < j){
            if(s[i++] != s[j--]){
                return false;
            }    
        }

        return true;
    }
};