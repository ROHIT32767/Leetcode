class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        vector<vector<int>> dp(size+4,vector<int>(2,-1));
        dp[size][0] = 0;
        dp[size][1] = 0;
        for(int index=size+3;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                int val = 0;
                if(index>=size){
                    val = 0;
                }
                else{
                    if(buy){
                        val = max(dp[index+1][1-buy]-prices[index],dp[index+1][buy]);
                    }
                    else{
                        val = max(dp[index+1][1-buy]+prices[index]-fee,dp[index+1][buy]);
                    }
                }
                dp[index][buy] = val;
            }
        }
        return dp[0][1];
    }
};