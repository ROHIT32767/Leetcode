class Solution {
public:
    int get_encoding(int r,int c,int rows){
        return r*rows+c;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(grid[0][0]==1 || grid[rows-1][cols-1]==1){
            return -1;
        }
        if(rows==1 && cols==1){
            return 1;
        }
        int size = rows*cols;
        vector<int> dist(size,1e9);
        dist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,0));
        vector<int> up = {-1,0,1};
        vector<int> right = {-1,0,1};
        while(!pq.empty()){
            pair<int,int> P = pq.top();
            int t_row = P.second/rows;
            int t_col = P.second%rows;
            pq.pop();
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i==1 && j==1){
                        continue;
                    }
                    int new_row = t_row + up[i];
                    int new_col = t_col + right[j];
                    if(new_row<0 || new_row>=rows || new_col<0 || new_col>=cols){
                        continue;
                    }
                    if(grid[new_row][new_col]==1){
                        continue;
                    }
                    int new_cell = get_encoding(new_row,new_col,rows);
                    if((dist[P.second]+1) < dist[new_cell]){
                            dist[new_cell] = 1 + dist[P.second];
                            if(new_cell==(size-1)){
                                return dist[new_cell]+1;
                            }
                            pq.push(make_pair(dist[new_cell],new_cell));
                        }
                    }
                }
        }
        return -1;
    }
};