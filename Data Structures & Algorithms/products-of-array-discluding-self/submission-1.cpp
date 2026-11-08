class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_products(n);
        vector<int> right_products(n);
        left_products[0] = 1;
        right_products[0] = 1;

        for(int i=1; i<n; i++){
            left_products[i] = nums[i-1] * left_products[i-1];
        }
        for(int i=n-2; i>=0; i--){
            int pos = n-1-i;
            right_products[pos] = nums[i+1] * right_products[pos-1];
        }

        vector<int> outputs;
        for(int i=0; i<n; i++) {
            outputs.push_back(left_products[i] * right_products[n-i-1]);
        }
        return outputs;
        
    }
};
