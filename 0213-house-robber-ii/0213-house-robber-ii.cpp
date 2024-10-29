class Solution {
public:
    int array_rob(vector<int> nums) {
        int size = nums.size();
        vector<int> dp(size+1,0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2;i<=size;i++){
            dp[i] = max(dp[i-1],nums[i-1]+dp[i-2]);
        };
        return dp[size];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        int first = array_rob(vector<int>(nums.begin(),nums.end()-1));
        int last = array_rob(vector<int>(nums.begin()+1,nums.end()));
        return max(last,first);
    }
};