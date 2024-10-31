class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,1));
        int count = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    dp[i][j] = 0;
                    continue;
                }
                if(i-1>=0 && j-1>=0){
                    if(dp[i-1][j] && dp[i][j-1] && dp[i-1][j-1]){
                        dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    }
                }
                count+=dp[i][j];
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return count;
    }
};