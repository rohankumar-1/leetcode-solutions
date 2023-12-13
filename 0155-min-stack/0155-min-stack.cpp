class MinStack {
public:
    stack<pair<int, int>> s;
    MinStack() {}
    
    void push(int val) {
        if(s.empty()){
            s.push(make_pair(val, val));
        }
        else{
            int currMin = min(getMin(), val);
            s.push(make_pair(val, currMin));
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        pair<int, int> curr = s.top();
        return curr.first;
    }
    
    int getMin() {
        pair<int, int> curr = s.top();
        return curr.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */