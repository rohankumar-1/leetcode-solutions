class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);     // convert to a string
        int middle = s.length() / 2; // find middle of the string

        for(int i = 0; i < middle; i++){
            if(s.at(i) != s.at(s.length()-i -1)){
                return false;
            }
        }

        return true;
    }
};