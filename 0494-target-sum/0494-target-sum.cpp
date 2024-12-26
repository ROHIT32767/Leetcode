class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        int total_sum = 0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }
        int sum = (total_sum+target)/2;
        if((total_sum+target)%2==1){
            return 0;
        }
        if(sum>total_sum || sum<0){
            return 0;
        }
        vector<vector<int>> dp(size+1,vector<int>(total_sum+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=size;i++){
            for(int total=0;total<=total_sum;total++){
                if(total>=nums[i-1]){
                    dp[i][total] = (dp[i-1][total] + dp[i-1][total-nums[i-1]]);
                }
                else{
                    dp[i][total] = dp[i-1][total];
                }
            }
        }
        return dp[size][sum];
    }
};