class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_price, profit, new_profit;
        profit = 0;
        new_profit = 0;
        if (prices.size()!=0){
            best_price = prices[0];
            for (int i=1; i<prices.size(); i++){
                if(prices[i] < best_price) best_price = prices[i];
                else{
                    new_profit = prices[i] - best_price;
                    if(new_profit > profit) profit = new_profit;
                }
            }
        }
        
        return profit;
    }
};
