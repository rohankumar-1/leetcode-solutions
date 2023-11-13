class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0; int i = 0;
        while(i < nums.size()){
            if(nums[i] != val){
                nums[idx] = nums[i];
                idx++;
            }
            i++;
        }
        return idx;
    }
};