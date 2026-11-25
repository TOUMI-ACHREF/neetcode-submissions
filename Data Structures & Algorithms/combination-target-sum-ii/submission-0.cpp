class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int> &current, int index, vector<vector<int>> &solutions){
        if(target == 0) {
            solutions.push_back(current);
            return;
        }
        
        for (int i = index; i<candidates.size(); i++){
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            
            current.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], current, i+1, solutions);
            current.pop_back();
        }
    }
        
    

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> solutions;
        vector<int> current;
        backtrack(candidates, target, current, 0, solutions);
        return solutions;
    }
};
