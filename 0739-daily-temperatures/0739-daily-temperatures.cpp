class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> S;
        int size = temperatures.size();
        vector<int> vect(size,0);
        for(int i=size-1;i>=0;i--)
        {
            while(S.size() && temperatures[S.top()]<=temperatures[i])
            {
                S.pop();
            }
            if(S.size()==0)
            {
                vect[i]=0;
            }
            else
            {
                vect[i]=S.top()-i;
            }
            S.push(i);
        }
        return vect;
    }
};