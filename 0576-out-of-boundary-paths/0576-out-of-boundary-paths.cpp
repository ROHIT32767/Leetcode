class Solution {
public:
        typedef long long int INT;
        INT mod = 1e9+7;
        int recursion(int row,int column,int m,int n,vector<vector<vector<INT>>>& dp,int moves_left){
        if(row<0 || row>=m || column<0 || column>=n){
            return 1;
        }
        if(moves_left==0){
            return 0;
        }
        if(dp[row][column][moves_left]!=-1){
            return dp[row][column][moves_left]%mod;
        }
        INT ans=0;
        ans+=recursion(row+1,column,m,n,dp,moves_left-1)%mod;
        ans+=recursion(row-1,column,m,n,dp,moves_left-1)%mod;
        ans+=recursion(row,column+1,m,n,dp,moves_left-1)%mod;
        ans+=recursion(row,column-1,m,n,dp,moves_left-1)%mod;
        dp[row][column][moves_left]=ans%mod;
        return ans%mod;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<INT>>> dp(m,vector<vector<INT>>(n,vector<INT>(maxMove+1,-1)));
        return recursion(startRow,startColumn,m,n,dp,maxMove);
    }
};