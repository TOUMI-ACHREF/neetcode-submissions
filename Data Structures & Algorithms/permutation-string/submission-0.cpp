class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        else{
            int frequency[26] = {0};
            for(int i=0; i<s1.length(); i++){
                frequency[s1[i]-97]+=1;
            }

            int l=0;
            int r=s1.length();
            int current_frequency[26] = {0};
            for(int i=0; i<s1.length(); i++) current_frequency[s2[i]-97]+=1;
            while(r < s2.length()){
                if(equal(frequency, frequency + 26, current_frequency)) return true;
                else{
                    current_frequency[s2[l]-97]--;
                    current_frequency[s2[r]-97]++;
                    l++;
                    r++;
                }
            }
            return equal(frequency, frequency + 26, current_frequency);
        }
    }
};
