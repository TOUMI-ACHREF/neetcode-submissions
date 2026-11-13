class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> redendance;

        int l = 0;
        int r = 0;
        int longest = 0;
        int max_frequency = 0;
        while (r < s.length()) {
            redendance[s[r]]++;

            max_frequency = max(max_frequency, redendance[s[r]]);

            if ((r - l + 1) - max_frequency > k) {
                redendance[s[l]]--;
                l++;
            }

            longest = max(longest, r - l + 1);

            r++;
        }
        return longest;
    }
};
