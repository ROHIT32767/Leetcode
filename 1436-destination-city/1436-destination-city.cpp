class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,bool> from;
        map<string,bool> to;
        for(auto vect:paths)
        {
            from[vect[0]] = true;
            to[vect[1]] = true;
        }
        for(auto it:to)
        {
            if(!from[it.first])
            {
                return it.first;
            }
        }
        return "";
    }
};