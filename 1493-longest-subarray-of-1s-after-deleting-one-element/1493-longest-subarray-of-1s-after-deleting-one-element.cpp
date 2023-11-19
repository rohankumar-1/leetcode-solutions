class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0; int j = 0;
        int count = 0; int maxLen = 0;
        int k = 1;  // how many we can delete still

        while(j < nums.size()){
            if(nums[j] == 1){
                // if we hit a 1, increase count and move expand subarray
                count++;
                j++;
            }
            else{
                // if we hit 0, either we can delete (if k==1) or we can reset subarray
                // by incrementing left index until we have recovered the deleted element
                // (this will be first 0 found)
                if(k == 1){
                    k--;
                    j++;
                }
                else{
                    // we have used up deletion, so loop until the deletion is recovered
                    while(k < 1){
                        if(nums[i] == 0){
                            // if first elem is 0, this is our most recent deletion, reset k
                            k++;
                        }
                        else{
                            // else if elem is 1, we are moving past so decrement count
                            count--;
                        }
                        i++;
                    }
                }
            }

            maxLen = max(count, maxLen);
        }

        if(maxLen == nums.size()){
            maxLen--;
        }
        return maxLen;
    }
};