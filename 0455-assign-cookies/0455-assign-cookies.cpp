class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int size1 = g.size();
        int size2 = s.size();
        int index = 0;
        int position = 0;
        while(position<size1)
        {
            while(index<size2 && s[index]<g[position])
            {
                index++;
            }
            if(index==size2)
            {
                break;
            }
            position++;
            index++;
        }
        return position;
    }
};