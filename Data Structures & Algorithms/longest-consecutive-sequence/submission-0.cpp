class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> distincts(nums.begin(), nums.end());
      int n = nums.size();
      int longest_seq = 0;

      for(int i=0; i<n; i++){
        int current = nums[i];
        int current_seq = 0;
        if(!distincts.contains(current-1)){
            while(distincts.contains(current)){
                current_seq+=1;
                current+=1;
            }
            if(current_seq > longest_seq) longest_seq = current_seq;
        }
      }

      return longest_seq;
    }
};
