class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequences;

        for(int i=0; i<nums.size(); i++){
            if(frequences.find(nums[i]) == frequences.end()){
                frequences[nums[i]] = 1;
            }else{
                frequences[nums[i]] += 1;
            }
        }

        vector<pair<int, int>> vec(frequences.begin(), frequences.end());

        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; 
        });

        vector<int> outputs;
        for (int i = 0; i < k; i++) {
            outputs.push_back(vec[i].first);
        }
        return outputs;
    }
};
