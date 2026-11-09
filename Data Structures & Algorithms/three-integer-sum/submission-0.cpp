class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> outputs;
        int target, r, l;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            target = 0-nums[i];
            r = nums.size()-1;
            l=i+1;
            while(l<r){
                if ((target - nums[r]) == nums[l]){
                    outputs.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while(l < r && nums[l] == nums[l-1])
                        l++;

                    while(l < r && nums[r] == nums[r+1])
                        r--;
                }
                else if ((target - nums[r]) > nums[l]) {
                    l++;
                }
                else{
                    r--; 
                }
            }
        }
        return outputs;
    }
};
