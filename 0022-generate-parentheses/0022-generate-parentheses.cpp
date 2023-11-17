class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        stack<char> st;
        string curr = "";
        gen(n*2, curr, st);
        return res;
    }

    void gen(int n, string curr, stack<char>& st){
        cout << n << " " << curr << endl;
        if(n == 0){
            // if we have used all parenthesis and stack is empty, add to result
            if(st.empty()){    
                cout << "empty" << endl;
                res.push_back(curr);
            }
            return;
        }
        else {
            // try adding '('
            curr.push_back('(');
            st.push('(');
            gen(n-1, curr, st);

            // revert
            curr.pop_back();
            st.pop();

            // try adding ')'
            bool popped = false;
            curr.push_back(')');
            cout << "Size: " << st.size() << endl;
            if(!st.empty() && st.top() == '('){
                popped = true;
                st.pop();
            }
            else{
                st.push(')');
            }
            gen(n-1, curr, st);

            curr.pop_back();
            if(popped){
                st.push('(');
            }
            else{
                st.pop();
            }
            return;
        }
    }
};