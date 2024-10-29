class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> sum(row,vector<int>(col,0));
        sum[0][0] = grid[0][0];
        for(int i=1;i<row;i++){
            sum[i][0] += grid[i][0] + sum[i-1][0];
        }
        for(int i=1;i<col;i++){
            sum[0][i] += grid[0][i] + sum[0][i-1];
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                sum[i][j] = grid[i][j] + min(sum[i][j-1],sum[i-1][j]);
            }
        }
        return sum[row-1][col-1];
    }
};