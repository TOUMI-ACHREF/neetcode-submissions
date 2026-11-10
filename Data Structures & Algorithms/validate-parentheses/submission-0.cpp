class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        char last_opened;
        unordered_map<char, char> validation = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        }; 
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                parentheses.push(s[i]);
            }else{
                if(!parentheses.empty()){
                    last_opened = parentheses.top();
                    if (validation.find(last_opened)->second != s[i]) return false;
                    else parentheses.pop();
                }
                else return false;
            }
        }
        if(parentheses.empty()) return true;
        else return false;
    
    }
};
