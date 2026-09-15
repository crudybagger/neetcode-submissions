class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mProfit = 0;
        for(int buy = 0; buy < prices.size(); buy++){
            for(int sell = buy; sell < prices.size(); sell++) {
                mProfit = max(mProfit, prices[sell] - prices[buy]);
            }
        }
        return mProfit;
    }
};
