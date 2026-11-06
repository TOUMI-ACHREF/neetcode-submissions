class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphabets[26] = {0};

        for (int i=0; i<s.length(); i++){
            alphabets[s[i]-'a']+=1;
        }
        for (int i=0; i<t.length(); i++){
            alphabets[t[i]-'a']-=1;
        }
        for (int i=0; i<26; i++){
            if (alphabets[i]!=0) return false;
        }
        return true;
    }
};
