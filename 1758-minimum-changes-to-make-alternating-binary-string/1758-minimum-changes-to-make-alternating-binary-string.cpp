class Solution {
public:
    int hamming_function(string s1,string s2)
    {
        int size = s1.size();
        int count = 0;
        for(int i=0;i<size;i++)
        {
            if(s1[i]==s2[i])
            {
                count++;
            }
        }
        return count;
    }
    int minOperations(string s) {
        string s1 = "";
        string s2 = "";
        int num = 0;
        for(int i=0;i<s.size();i++)
        {
            s1.push_back(num+48);
            s2.push_back(49-num);
            num = 1-num;
        }
        int similarity1 = hamming_function(s1,s);
        int similarity2 = hamming_function(s2,s);
        return similarity1 > similarity2 ? s.size()-similarity1 : s.size()-similarity2;
    }
};