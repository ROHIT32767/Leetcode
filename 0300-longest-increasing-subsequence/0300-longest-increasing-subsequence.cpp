class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,1);
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int MAX = INT_MIN;
        for(int i=0;i<size;i++){
            MAX = max(MAX,dp[i]);
        }
        return MAX;
    }
};