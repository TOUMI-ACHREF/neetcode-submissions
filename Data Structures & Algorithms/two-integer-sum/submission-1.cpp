class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> seen;
        vector<int> result;
        for (int i=0; i<nums.size(); i++){
            int sub = target - nums[i];
            if (seen.find(sub) == seen.end()){
                seen[nums[i]] = i;
            }else {
                result.push_back(seen[sub]);
                result.push_back(i);
                return result;
            }
        }
    }
};
