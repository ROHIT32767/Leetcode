class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        if(coins.size()==0){
            return 0;
        }
        int size = coins.size();
        vector<vector<uint32_t>> dp(size+1,vector<uint32_t>(amount+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=size;i++){
            for(int charge=0;charge<=amount;charge++){
                    if(charge>=coins[i-1]){
                        dp[i][charge] = dp[i][charge-coins[i-1]]+dp[i-1][charge];
                    }
                    else{
                        dp[i][charge] = dp[i-1][charge];
                    }
                
            }
        }
        return dp[size][amount];
    }
};