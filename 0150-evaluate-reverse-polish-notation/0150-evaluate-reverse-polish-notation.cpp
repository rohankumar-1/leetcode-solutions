class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        
        
        
        for(auto n : tokens){
            if(n == "+"){
                int x1 = s.top(); s.pop();
                int x2 = s.top(); s.pop();
                s.push(x1+x2);
            }
            else if(n == "/"){
                int x1 = s.top(); s.pop();
                int x2 = s.top(); s.pop();
                s.push(x2/x1);
            }
            else if(n == "*"){
                int x1 = s.top(); s.pop();
                int x2 = s.top(); s.pop();
                s.push(x2*x1);
            }
            else if(n == "-"){
                int x1 = s.top(); s.pop();
                int x2 = s.top(); s.pop();
                s.push(x2-x1);
            }
            else{
                s.push(stoi(n));
            }
        }
        
        return s.top();
    }
};