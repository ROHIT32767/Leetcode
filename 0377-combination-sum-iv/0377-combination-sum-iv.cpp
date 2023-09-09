class Solution {
public:
    
    int backtrack(int sum,vector<int>& nums,vector<int>& dp)
    {
        if(sum==0)
        {
            return dp[sum]=1;
        }
        int count = 0;
        if(dp[sum]!=-1)
        {
            return dp[sum];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(sum-nums[i]>=0)
            {
               count += backtrack(sum-nums[i],nums,dp);
            }
        }
        return dp[sum]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int ans = 0;
        vector<int> dp(target+1,-1);
        backtrack(target,nums,dp);
        return dp[target];
    }
};