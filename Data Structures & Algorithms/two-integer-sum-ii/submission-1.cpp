class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int rest;
        int r = numbers.size()-1;
        int l=0;
        while(l<r){
            rest = target - numbers[r];
            if (rest == numbers[l]) return {l+1,r+1};

            if (rest>numbers[l]) l++;
            else r--;
        }
        return {};
    }
};
