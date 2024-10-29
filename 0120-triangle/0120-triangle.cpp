class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<vector<int>> dp;
        dp.push_back(triangle[0]);
        for(int i=1;i<size;i++){
            int row_size = triangle[i].size();
            vector<int> temp_row(row_size,0);
            for(int j=0;j<row_size;j++){
                if(j==0){
                    temp_row[j] = dp[i-1][j];
                }
                else if(j==row_size-1){
                    temp_row[j] = dp[i-1][j-1];
                }
                else{
                    temp_row[j] = min(dp[i-1][j],dp[i-1][j-1]);
                }
                temp_row[j] += triangle[i][j];
            }
            dp.push_back(temp_row);
        }
        int MIN = INT_MAX;
        for(int i=0;i<dp[dp.size()-1].size();i++){
            MIN = min(MIN,dp[dp.size()-1][i]);
        }
        return MIN;
    }
};