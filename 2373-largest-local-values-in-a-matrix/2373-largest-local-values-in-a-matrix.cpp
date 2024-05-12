class Solution {
public:
    long long int max(long long int A,long long int B){
        return A<B ? B: A;
    }
    long long int window_maximum(vector<vector<int>>& grid,int row,int column){
        long long int MAX = INT_MIN;
        for(int i=row;i<row+3;i++){
            for(int j=column;j<column+3;j++){
                MAX = max(MAX,grid[i][j]);
            }
        }
        return MAX;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> local(n-2,vector<int>(n-2,-1));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                local[i][j] = window_maximum(grid,i,j);
            }
        }
        return local;
    }
};