class Solution {
public:
    typedef long long int INT;
    int max(int a,int b)
    {
        if(a<b)
        {
            return b;
        }
        return a;
    }
    INT func(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int R1 , int C1 , int C2)
    {
        INT R2 = R1;
        int n = grid.size();
        int columns = grid[0].size();
        if(R1<0 || R2<0 || R1>=n || R2>=n || C1<0 || C2<0 || C1>=columns || C2>=columns)
        {
            return 0;
        }
        if(R1==n)
        {
            return 0;
        }
        if(dp[R1][C1][C2]!=-1)
        {
            return dp[R1][C1][C2];
        }
        INT result = grid[R1][C1];
        result+= grid[R2][C2];
        INT MAX = 0;
        for(int x=C1-1;x<=C1+1;x++) {
            for(int y=C2-1;y<=C2+1;y++) {
                if(x < y) { 
                    MAX = max(MAX, func(grid,dp,R1+1,x,y));
                }
            }
        }
        result += MAX;
        return dp[R1][C1][C2]=result;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int size = grid.size();
        int columns = grid[0].size();
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(columns+1,vector<int>(columns+1,-1)));
        return max(0,func(grid,dp,0,0,grid[0].size()-1));
    }
};