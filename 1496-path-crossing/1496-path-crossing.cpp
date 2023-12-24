class Solution {
public:
    pair<int,int> next_coordinate(pair<int,int> P,char ch)
    {
        if(ch=='N')
        {
            return {P.first,P.second+1};
        }
        else if(ch=='S')
        {
            return {P.first,P.second-1};
        }
        else if(ch=='W')
        {
            return {P.first-1,P.second};
        }
        return {P.first+1,P.second};
    }
    bool isPathCrossing(string path) {
        map<pair<int,int>,int> M;
        pair<int,int> start = make_pair(0,0);
        int size = path.size();
        for(int i=0;i<size;i++)
        {
            M[start] = 1;
            start = next_coordinate(start,path[i]);
            if(M[start]==1)
            {
                return true;
            }
        }
        return false;
        
        
    }
};