class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(2,vector<int>(3,-1)));
        for(int index=size;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                for(int day=0;day<3;day++){
                    int val = 0;
                    if(index==size){
                        val = 0;
                    }
                    else{
                        if(buy){
                            val = max(dp[index+1][1-buy][day]-prices[index],dp[index+1][buy][day]);
                        }
                        else{
                            if(day==2){
                                val = 0;
                            }
                            else{
                                val = max(dp[index+1][1-buy][day+1]+prices[index],dp[index+1][buy][day]);
                            }
                        }
                    }
                    dp[index][buy][day] = val;
                }
            }
        }
        return dp[0][1][0];
    }
};