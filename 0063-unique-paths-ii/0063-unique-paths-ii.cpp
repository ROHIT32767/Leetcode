class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> comb(m,vector<int>(n,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    comb[i][j] = 0;
                }
            }
        }
        for(int i=1;i<m;i++){
            comb[i][0] = comb[i][0] == 0 ? comb[i][0] : comb[i-1][0];
        }
        for(int i=1;i<n;i++){
            comb[0][i] = comb[0][i] == 0 ? comb[0][i] : comb[0][i-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(comb[i][j]==0){
                    continue;
                }
                comb[i][j] = comb[i-1][j] + comb[i][j-1];
            }
        }
        return comb[m-1][n-1];
    }
};