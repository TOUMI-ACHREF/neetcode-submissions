class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = 0;
        for (int i=0; i<n; i++){
            if(piles[i]>m) m = piles[i];
        }
        int l = 1;
        int r = m;
        int i = 0;
        while(l<=r){
            int current_k = l + (r-l)/2;
            long long hours = 0;
            i=0;
            while(i<n && hours<=h){
                hours+= (piles[i] + current_k - 1) / current_k;;
                i++;
            }
            
            //binary search logic
            if (hours>h) l = current_k+1;
            else r = current_k-1;
        }
        return l;
    }
};
