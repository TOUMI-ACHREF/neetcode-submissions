class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int longest = 0;
        unordered_set<char> uniques;

        while (r<s.length()){
            if(uniques.contains(s[r])){
                uniques.erase(s[l]);
                l++;
            }else{
                uniques.insert(s[r]);
                if(uniques.size() > longest) longest = uniques.size();
                r++;
            }
            
        }
        return longest;

    }
};

