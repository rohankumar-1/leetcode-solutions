class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for(auto c : s){
            if(res.empty()){
                res.push(c);
                continue;
            }
            char top = res.top();
            if(top == '('){
                if(c == ')'){ res.pop(); }
                else res.push(c);
            }
            else if(top == '{'){
                if(c == '}'){ res.pop(); }
                else res.push(c);
            }
            else if(top == '['){
                if(c == ']'){ res.pop(); }
                else res.push(c);
            }
            else{
                return false;
            }
        }
        
        return res.empty();
    }
};