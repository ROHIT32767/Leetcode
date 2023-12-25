class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(n+1,0);
        if(n<=1)
        {
            return n;
        }
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
            {
                dp[i] = dp[i/2];
                continue;
            }
            dp[i] = dp[i/2]+dp[i/2+1];
        }
        sort(dp.begin(),dp.end());
        return dp[n];
    }
};