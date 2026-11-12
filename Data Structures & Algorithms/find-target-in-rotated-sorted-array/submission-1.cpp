class Solution {
public:
    int findMin(vector<int> nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]) l = mid+1;
            else r = mid;
        
        }
        return l;
    }

    int binarySearch(vector<int> nums, int target, int l, int r) {
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int cut = findMin(nums);
        if(cut == 0) return binarySearch(nums,target, 0, nums.size()-1);
        else{
            int res_seg1 = binarySearch(nums,target, 0, cut-1);
            if(res_seg1 != -1) return res_seg1;
            else return binarySearch(nums,target, cut, nums.size()-1);
        }
    }
};
