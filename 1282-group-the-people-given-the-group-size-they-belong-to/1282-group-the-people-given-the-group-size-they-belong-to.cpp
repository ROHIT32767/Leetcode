class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> M;
        int size = groupSizes.size();
        for(int i=0;i<size;i++)
        {
            M[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(auto node:M)
        {
            int group_size = node.first;
            vector<int> vect(group_size,-1);
            for(int i=0;i<node.second.size();i++)
            {
                vect[i%group_size] = (node.second)[i];
                int num = i+1;
                if(i%group_size==group_size-1)
                {
                    res.push_back(vect);
                }
            }
        }
        return res;
    }
};