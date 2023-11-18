class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        double maxSum = sum;
        
        int i = 0; int j = k;

        while(j < nums.size()){
            sum -= nums[i];
            sum += nums[j];
            if(sum > maxSum){
                maxSum = sum;
            }
            i++; j++;
        }

        return (maxSum / k);
    }
};