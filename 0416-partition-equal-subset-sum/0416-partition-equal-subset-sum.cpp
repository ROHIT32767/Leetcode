class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for(int i=0;i<size;i++){
            sum += nums[i];
        }
        if(sum%2==1){
            return false;
        }
        sum = sum/2;
        vector<vector<bool>> dp(size+1,vector<bool>(sum+1,0));
        dp[0][0] = true;
        for(int i=1;i<=size;i++){
            for(int total=0;total<=sum;total++){
                if(total>=nums[i-1]){
                    dp[i][total] = dp[i-1][total] || dp[i-1][total-nums[i-1]];
                }
                else{
                    dp[i][total] = dp[i-1][total];
                }
            }
        }
        return dp[size][sum];
    }
};