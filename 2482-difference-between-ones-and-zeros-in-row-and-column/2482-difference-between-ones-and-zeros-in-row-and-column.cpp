class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // first compute for rows
        int rows = grid.size();
        int columns = grid[0].size();
        vector<int> ones_row(rows,0), ones_column(columns,0);
        for(int i=0;i<columns;i++)
        {
            int sum = 0;
            for(int j=0;j<rows;j++)
            {
                sum +=grid[j][i];
            }
            ones_column[i]=sum;
        }
        for(int i=0;i<rows;i++)
        {
            int sum = 0;
            for(int j=0;j<columns;j++)
            {
                sum +=grid[i][j];
            }
            ones_row[i]=sum;
        }
        vector<vector<int>> diff(rows,vector<int>(columns,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                diff[i][j]=2*ones_row[i]+2*ones_column[j]-rows-columns;
            }
        }
        return diff;
        
    }
};