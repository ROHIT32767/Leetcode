class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,1);
        vector<int> count(size,1);
        int MAX = 1;
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    int temp = dp[i];
                    dp[i] = max(dp[i],1+dp[j]);
                    if(1+dp[j]<dp[i]){
                        continue;
                    }
                    if(temp==(1+dp[j])){
                        count[i] += count[j];
                    }
                    else{
                        count[i] = count[j];
                    }
                    MAX = max(MAX,dp[i]);
                }
            }
        }
        int total_count = 0;
        for(int i=0;i<size;i++){
            if(dp[i]==MAX){
                total_count += count[i];
            }
        }
        return total_count;
    }
};