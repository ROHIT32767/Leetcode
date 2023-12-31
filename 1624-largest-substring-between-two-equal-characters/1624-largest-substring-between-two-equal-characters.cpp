class Solution {
public:
    typedef long long int INT;
    int max(int a,int b)
    {
        return a>b ? a:b;
    }
    int min(int a,int b)
    {
        return a>b ? b:a;
    }
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<int,int> M1,M2;
        int size = s.size();
        for(int i=0;i<size;i++)
        {
            if(M1[s[i]]==0)
            {
                M1[s[i]]=i+1;
            }
            M2[s[i]]=max(M2[s[i]],i+1);
        }
        INT MAX = INT_MIN;
        for(auto i:M1)
        {
            MAX = max(MAX,M2[i.first]-i.second);
        }
        return MAX-1;
    }
};