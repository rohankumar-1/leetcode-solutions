// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // this is just binary searching for the leftmost element that is bad
        int left = 1;
        int right = n;
        int firstBad;
        int mid;
        
        while(left <= right){
            mid = left + (right-left)/2;
            
            if(isBadVersion(mid)){
                // if mid is bad, then go to left subarray
                firstBad = mid;
                right = mid - 1;
            }
            else{
                // if mid is find, then go to right subarray
                left = mid + 1;
            }
        }
        
        return firstBad;
    }
};