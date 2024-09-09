class Solution {
public:
        vector<string> perp(string direction)
    {
        if(direction=="up"||direction=="down")
        {
            vector<string> vect{"left","right"};
            return vect;
        }
        if(direction=="right"||direction=="left")
        {
            vector<string> vect{"up","down"};
            
            return vect;
        }
        cout << "Unidentified Direction";
        return vector<string>{};
    }
    pair<int,int> move(pair<int,int> P,string direction)
    {
        if(direction=="up")
        {
            return make_pair(P.first-1,P.second);
        }
        if(direction=="down")
        {
            return make_pair(P.first+1,P.second);
        }
        if(direction=="left")
        {
            return make_pair(P.first,P.second-1);
        }
        if(direction=="right")
        {
            return make_pair(P.first,P.second+1);
        }
        cout << "Unidentified Direction";
        return make_pair(-1,-1);
    }
    vector<vector<int>> spiralOrder(vector<vector<int>>& matrix) {
        map<pair<int,int>,int> M;
        int R = matrix.size();
        int C = matrix[0].size();
        int flag=1;
        int row = 0;
        int column = 0;
        vector<int> vect;
        string direction = "right";
        long long int count = 1;
        while(direction=="up" || direction=="right" || direction=="down" || direction=="left")
        {
            matrix[row][column] = count;
            count++;
            M[make_pair(row,column)]=1;
            pair<int,int> next = move(make_pair(row,column),direction);
            if(next.first<0 || next.first>=R || next.second<0 || next.second>=C || M[next]==1)
            {
                vector<string> next_direction = perp(direction);
                direction = next_direction[0];
                next = move(make_pair(row,column),direction);
                if(next.first<0 || next.first>=R || next.second<0 || next.second>=C || M[next]==1)
                {
                    direction = next_direction[1];
                    next = move(make_pair(row,column),direction);
                    row = next.first;
                    column = next.second;
                    if(next.first<0 || next.first>=R || next.second<0 || next.second>=C || M[next]==1)
                    {
                        direction="";
                        break;
                    }
                    else
                    {
                        row = next.first;
                        column = next.second;
                    }
                }
                else
                {
                    row = next.first;
                    column = next.second;
                }
            }
            else
            {
                row = next.first;
                column = next.second;
            }
        }
        return matrix;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        return spiralOrder(matrix);
    }
};