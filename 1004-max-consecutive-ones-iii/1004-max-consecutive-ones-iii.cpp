class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0; int right = 0;
        int count = k;

        int maxLen = 0;

        while(right < nums.size()){
            if(nums[right] == 1){
                right++;
            }
            else{
                // nums[right] == 0, which means we need to decrement count
                count--;
                while(count < 0){
                    // we keep moving left while count is negative
                    if(nums[left] == 0){
                        // we are removing a 0, so we can flip another 0 in the future
                        count++;
                    }
                    left++;
                }
                right++;
            }

            maxLen = max(maxLen, right-left);
        } 

        return maxLen;
    }
};