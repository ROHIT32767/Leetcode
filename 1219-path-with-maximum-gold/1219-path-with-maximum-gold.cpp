class Solution {
public:
    int recursion(int row,int column,vector<vector<int>>& grid){
        if(row<0 || column<0 || row>=grid.size() || column>=grid[0].size()){
            return 0;
        }
        if(grid[row][column]==0){
            return 0;
        }
        int val = grid[row][column];
        grid[row][column] = 0;
        int MAX = 0;
        MAX = max(recursion(row+1,column,grid),recursion(row,column+1,grid));
        MAX = max(MAX,recursion(row-1,column,grid));
        MAX = max(MAX,recursion(row,column-1,grid));
        grid[row][column] = val;
        return grid[row][column] + MAX;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int MAX = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                MAX = max(recursion(i,j,grid),MAX);
            }
        }
        return MAX;
    }
};