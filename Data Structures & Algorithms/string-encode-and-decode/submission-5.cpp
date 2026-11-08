class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "case-1";
        if(strs.size() == 1 && strs[0]=="") return "case-2";
        string s = strs[0];
        for (int i=1; i<strs.size(); i++){
            s+= "-space-";
            s+= strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> decoded_str;
        string str="";
        if (s == "case-1") return decoded_str;
        else{
            if (s == "case-2") decoded_str.push_back("");
            else{
                bool is_space = false;
                for(int i=0; i<s.length(); i++){
                    if(i+7<= s.length() && s.substr(i, 7) == "-space-") is_space = true;
                    else is_space = false;

                    if(is_space){
                        decoded_str.push_back(str);
                        str = "";
                        i+=6;
                    }else{
                        str = str + s[i];
                    }
                }
                decoded_str.push_back(str);
            }
            
            return decoded_str;
        }
        
    }
};
