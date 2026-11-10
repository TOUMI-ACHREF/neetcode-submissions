class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int n = height.size();
        int r = n-1;
        int water_level = 0;
        int output=0;
        int max_l=0;
        int max_r=0;
        while(l<r){
            max_l = max(max_l, height[l]);
            max_r = max(max_r, height[r]);
            
            if(max_l < max_r){
                output += max_l-height[l];
                l++;
            }else{
                output += max_r-height[r];
                r--;
            }

        }
        return output;
    }
};
