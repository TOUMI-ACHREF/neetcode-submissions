class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> mySet(nums.begin(), nums.end());
        if (nums.size() == mySet.size()) return false;
        else return true;
    }
};