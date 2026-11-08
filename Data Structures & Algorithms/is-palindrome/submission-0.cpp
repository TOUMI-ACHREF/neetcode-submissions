class Solution {
public:
    bool isPalindrome(string s) {
        int l_index = 0;
        int r_index = s.length()-1;
        while(l_index < r_index){
            while (!isalnum(s[l_index]) && l_index < r_index) l_index++;
            while (!isalnum(s[r_index]) && l_index < r_index) r_index--;
            if(tolower(s[l_index]) != tolower(s[r_index])) return false;
            else{
                l_index++;
                r_index--;
            }
        }
        return true;
    }
};
