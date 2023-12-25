class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        vector<int> dp(size+1,0);
        map<string,int> M;
        dp[0]=1;
        for(int i=1;i<=26;i++)
        {
            M[to_string(i)]=1;
        }
        for(int i=1;i<=size;i++)
        {
            dp[i]=0;
            char ch = s[i-1];
            if(ch!='0')
            {
                dp[i]+=dp[i-1];
            }
            if(i-2>=0)
            {
                string temp = "";
                temp.push_back(s[i-2]);
                temp.push_back(s[i-1]);
                if(M[temp]==1)
                {
                    dp[i]+=dp[i-2];
                }
            }
        }
        return dp[size];
    }
};