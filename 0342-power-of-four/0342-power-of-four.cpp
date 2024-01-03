class Solution {
public:
    bool isPowerOfFour(int n) {
        int m = n;
        while(m%4==0 && m>0)
        {
            m = m/4;
        }
        if(m==1)
        {
            return true;
        }
        return false;
    }
};