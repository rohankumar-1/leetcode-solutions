class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int minPrice = prices[0];

        int currProf;

        for(auto p : prices){
            if(p < minPrice){
                minPrice = p;
            }
            else if(p > minPrice){
                currProf = p - minPrice;
                if(currProf > mp){
                    mp = currProf;
                }
            }
        }

        return mp;
    }
};