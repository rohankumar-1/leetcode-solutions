class SmallestInfiniteSet {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> st;

    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++){
            st.insert(i);
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int item = pq.top(); pq.pop();
        st.erase(item);
        return item;
    }
    
    void addBack(int num) {
        if(st.count(num) == 0){
            // we can insert
            st.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */