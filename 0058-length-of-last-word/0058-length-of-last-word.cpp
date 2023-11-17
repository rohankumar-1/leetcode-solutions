class Solution {
public:
    int lengthOfLastWord(string s) {
        
        // find last char in string
        int j = s.length()-1;
        while(s.size() > 0 && s[s.size()-1] == ' '){
            s.pop_back();
        }

        // iterate over string backwards until we find next space or end
        int c = 0;
        while(s.size() > 0 && s[s.size()-1] != ' '){
            s.pop_back();
            c++;
        }

        return c;
    }
};