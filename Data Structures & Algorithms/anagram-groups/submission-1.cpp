class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<array<int, 26>> alphabet_string;
        map<array<int, 26>, vector<string>> groups;
        for (int i=0; i<strs.size(); i++){
            array<int, 26> alphabets = {0};
            for (int j=0; j<strs[i].length(); j++){
                alphabets[strs[i][j]-'a']+=1;
            }

            if(groups.find(alphabets) == groups.end())
                groups[alphabets] = {strs[i]};
            else
                groups[alphabets].push_back(strs[i]);
        }

        vector<vector<string>> outputs;
        outputs.reserve(groups.size());
        for (auto const& [key, value] : groups) {
            outputs.push_back(value); 
        }
        return outputs;
    };
};
