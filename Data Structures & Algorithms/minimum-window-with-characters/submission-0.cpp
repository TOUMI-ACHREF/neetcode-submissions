
class Solution {
public:
    string minWindow(string s, string t) {

        if(t.empty() || s.size() < t.size()) return "";

        unordered_map<char, int> frequencies;

        for(int i = 0; i < t.length(); i++){
            frequencies[t[i]]++;
        }

        int l = 0;
        int r = 0;

        int minStart = 0;
        int minLength = INT_MAX;

        while(r < s.length()){

            // Expand the window
            if(frequencies.find(s[r]) != frequencies.end()){
                frequencies[s[r]]--;
            }

            r++;

            // Check if all required characters are present
            bool allZero = all_of(frequencies.begin(), frequencies.end(), [](const auto& p) {
                    return p.second <= 0;
                }
            );

            // Shrink the window while it remains valid
            while(allZero && l < r){

                if(r - l < minLength){
                    minLength = r - l;
                    minStart = l;
                }

                if(frequencies.find(s[l]) != frequencies.end()){
                    frequencies[s[l]]++;
                }

                l++;

                allZero = all_of(frequencies.begin(), frequencies.end(), [](const auto& p) {
                        return p.second <= 0;
                    }
                );
            }
        }

        if(minLength == INT_MAX) return "";

        return s.substr(minStart, minLength);
    }
};
