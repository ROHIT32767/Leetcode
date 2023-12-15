class Solution {
public:
    bool recursion(int n,vector<int>& dp)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        if(n==0)
        {
            return dp[n]=true;
        }
        if(n==1)
        {
            return dp[n]=false;
        }
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                if(!(recursion(n-i,dp)) || !(recursion(n-n/i,dp)))
                {
                    return dp[n]=true;
                }
            }
        }
        return dp[n]=false;
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1,-1);
        return recursion(n,dp);
    }
};