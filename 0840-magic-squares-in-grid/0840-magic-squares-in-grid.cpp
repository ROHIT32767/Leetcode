class Solution {
public:
    bool check(vector<vector<int>>& grid,int row,int column){
        set<int> S;
        for(int i=row;i<row+3;i++){
            for(int j=column;j<column+3;j++){
                S.insert(grid[i][j]);
                if(grid[i][j]<1 || grid[i][j]>9){
                    return false;
                }
            }
        }
        if(S.size()!=9)
        {
            return false;
        }
        int sum = grid[row][column] + grid[row+1][column+1] + grid[row+2][column+2];
        if(sum!=(grid[row][column+2] + grid[row+1][column+1] + grid[row+2][column])){
            return false;
        }
        for(int i=row;i<row+3;i++){
            int temp = 0;
            for(int j=column;j<column+3;j++){
                temp += grid[i][j];
            }
            if(temp!=sum){
                return false;
            }
        }
        for(int j=column;j<column+3;j++){
            int temp = 0;
            for(int i=row;i<row+3;i++){
                temp += grid[i][j];
            }
            if(temp!=sum){
                return false;
            }
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        long long count = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        for(int i=0;i<rows-2;i++){
            for(int j=0;j<columns-2;j++){
                if(check(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};