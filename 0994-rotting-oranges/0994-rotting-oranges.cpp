class Solution {
public:
    bool check(int r,int c,int rows,int cols){
        if(r<0 || c<0 || r>=rows || c>= cols){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        queue<pair<int,int>> Q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    Q.push(make_pair(i,j));
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> up = {0,-1,0,1};
        vector<int> right = {-1,0,1,0};
        int count = 0;
        while(!Q.empty()){
            int size = Q.size();
            for(int j=0;j<size;j++){
                pair<int,int> P = Q.front();
                Q.pop();
                for(int i=0;i<4;i++){
                    int new_row = P.first + up[i];
                    int new_col = P.second + right[i];
                    if(check(new_row,new_col,rows,cols) && grid[new_row][new_col]==1 && vis[new_row][new_col]==0){
                        if(!vis[new_row][new_col]){
                            vis[new_row][new_col] = 1;
                            Q.push(make_pair(new_row,new_col));
                        }
                    }
                }
            }
            count++;
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count ==0 ? 0 : count-1;
    }
};