class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<array<int, 26>> alphabet_string;
        for (int i=0; i<strs.size(); i++){
            array<int, 26> alphabets = {0};
            for (int j=0; j<strs[i].length(); j++){
                alphabets[strs[i][j]-'a']+=1;
            }
            alphabet_string.push_back(alphabets);
        }
        map<array<int, 26>, vector<string>> groups;
        for (int i=0; i<strs.size(); i++){
            if(groups.find(alphabet_string[i]) == groups.end())
                groups[alphabet_string[i]] = {strs[i]};
            else
                groups[alphabet_string[i]].push_back(strs[i]);
        }

        vector<vector<string>> outputs;
        outputs.reserve(groups.size());
        for (auto const& [key, value] : groups) {
            outputs.push_back(value); 
        }
        return outputs;
    };
};
