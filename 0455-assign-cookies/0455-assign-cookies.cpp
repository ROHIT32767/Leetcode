class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index1 = 0;
        int index2 = 0;
        int count = 0;
        while(index1<g.size() && index2<s.size()){
            if(g[index1]<=s[index2]){
                count++;
                index1++;
            }
            index2++;
        }
        return count;
    }
};