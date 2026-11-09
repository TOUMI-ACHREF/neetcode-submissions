class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int l = 0;
        int r = heights.size()-1;
        int area,min_borne;

        while (l<r){
            if(heights[l]<heights[r]) min_borne = heights[l];
            else min_borne = heights[r];
            area = min_borne * (r-l);
            if (area > max_area) max_area = area;
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return max_area;
    }
};
