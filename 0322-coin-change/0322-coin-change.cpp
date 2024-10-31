class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        if(coins.size()==0){
            return -1;
        }
        int size = coins.size();
        vector<vector<int>> dp(size+1,vector<int>(amount+1,0));
        for(int j=1;j<=amount;j++){
            dp[0][j] = INT_MAX/2;
        }
        for(int i=1;i<=size;i++){
            for(int charge=0;charge<=amount;charge++){
                if(i==1 && charge%coins[i-1]!=0){
                    dp[i][charge] = INT_MAX/2;
                }
                else{
                    if(charge>=coins[i-1]){
                        dp[i][charge] = min(1+dp[i][charge-coins[i-1]],dp[i-1][charge]);
                    }
                    else{
                        dp[i][charge] = dp[i-1][charge];
                    }
                }
            }
        }
        return dp[size][amount]==(INT_MAX)/2 ?-1:dp[size][amount];
    }
};