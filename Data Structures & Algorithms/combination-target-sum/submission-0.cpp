class Solution {
public:
    void backtrack(vector<int>& nums, int target, int index, vector<int> &current_state, vector<vector<int>> &result){
        if (target == 0) {
            result.push_back(current_state);
        }else if(target < 0) return;
        else{
            for(int i=index; i<nums.size(); i++){
                if (nums[i] > target) break;
                current_state.push_back(nums[i]);
                backtrack(nums, target - nums[i], i, current_state, result);
                current_state.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current_state;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, current_state, result);
        return result;
    }
};
