class Solution {
public:
    int max(int a,int b)
    {
        return a>b ? a : b;
    }
    int maxScore(string s) {
        int size = s.size();
        int total_zeroes = 0;
        int total_ones = 0;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='0')
            {
                total_zeroes++;
            }
        }
        total_ones = size-total_zeroes;
        int MAX = INT_MIN;
        int current_zeroes = 0;
        for(int i=0;i<size-1;i++)
        {
            if(s[i]=='0')
            {
                current_zeroes++;
            }
            MAX = max(MAX,current_zeroes+total_ones-(i+1-current_zeroes));
        }
        return MAX;
    }
};