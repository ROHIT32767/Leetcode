class Solution {
public:
    int solve(int start,int end,vector<vector<int>>& dp,string& s)
    {
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        else if(start==end)
        {
            return 1;
        }
        else if(start>end)
        {
            return 0;
        }
        else
        {
            int turns = INT_MAX;
            for(int k=start+1;k<=end;k++)
            {
                int temp = solve(start,k-1,dp,s)+solve(k,end,dp,s);
                if(s[start]==s[end])
                {
                    temp--;
                }
                turns=min(turns,temp);
            }
            return dp[start][end]=turns;
        }
    }
    int strangePrinter(string s) {
        int size = s.size();
        vector<vector<int>> dp(size,vector<int>(size,-1));
        for(int i=0;i<size;i++)
        {
            dp[i][i]=1;
        }
        solve(0,size-1,dp,s);
        return dp[0][size-1];
    }
};