class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // half = (m+n+1)/2
        // x = mid
        // y = half-x
        int n = nums1.size();
        int m = nums2.size();
        int left=0;
        if (n > m){
            swap(nums1, nums2);
            swap(n, m);
        }
        int right = n;
        int half = (m+n+1)/2;

        while(left <= right){
            int x = left + (right-left)/2;
            int y = half - x;

            int left1  = (x == 0) ? INT_MIN : nums1[x-1];
            int right1 = (x == n) ? INT_MAX : nums1[x];
            int left2  = (y == 0) ? INT_MIN : nums2[y-1];
            int right2 = (y == m) ? INT_MAX : nums2[y];

            if (left1 <= right2 && left2 <= right1){
                if ((m+n)%2 == 1) return max(left1, left2);
                else return (max(left1, left2)+min(right1, right2))/2.0;
            }else if (left2 > right1){
                left = x+1;
            }else right = x-1;
        }
        return 0.0;
    }
};
