class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto s : stones){
            pq.push(s);
        }

        int item1; int item2; int diff;
        while(pq.size() > 1){
            item1 = pq.top(); pq.pop();
            item2 = pq.top(); pq.pop();
            diff = item1 - item2;
            if(diff != 0){
                pq.push(diff);
            }
        }


        return pq.empty() ? 0 : pq.top();
    }   
};