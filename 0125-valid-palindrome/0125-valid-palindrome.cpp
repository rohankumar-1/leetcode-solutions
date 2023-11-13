class Solution {
public:
    bool isPalindrome(string s) {
        
        string str = "";
        
        for(auto c : s){
            if(c != ' ' && isalnum(c)){
                str += tolower(c);
            }
        }

        int i = 0; int j = str.length()-1;

        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }

        return true;
    }
};