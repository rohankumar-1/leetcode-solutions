class Solution {
public:
    int maxArea(vector<int>& height) {
        // start max as area of first two containers
        int max = 0;

        int a = 0;
        int z = height.size()-1;

        while(a < z){
            // calculate height
            int h = min(height[a], height[z]);
            if(h*(z-a) > max){
                max = h*(z-a);
            }
            while(height[a] <= h && a < z){
                a++;
            }
            while(height[z] <= h && a < z){
                z--;
            }
        }

        return max;
    }
};