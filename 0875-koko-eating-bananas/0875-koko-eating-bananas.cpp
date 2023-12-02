class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // set low as 1 (minimum rate), high as max element (max rate)
        int low = 1; int high = *(max_element(piles.begin(), piles.end()));
        
        int mid;
        int currMin = high;
        while(low <= high){
            // find new mid
            mid = low + (high - low) / 2;

            // check if 'mid' bananas per hour is possible
            long int hours = 0;
            for(auto p : piles){
                if(p % mid != 0){
                    hours++;
                }
                hours += p / mid;  
            }
            
            if(hours > h){
                // rate is too slow, need to increase mid
                low = mid + 1;
            }
            else{
                // rate works, still we can check for lower rate
                high = mid - 1;
                currMin = min(currMin, mid);
            }
        }

        return currMin;
    }
};