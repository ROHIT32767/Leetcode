class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> vect[numRows];
        int size = s.size();
        int row = 0;
        for(int index = 0;index<size;index++)
        {
            if(row==0)
            {
                int count = 0;
                while(index<size && row<numRows)
                {
                    vect[row].push_back(s[index]);
                    row++;
                    index++;
                }
                index--;
                row = numRows-2;
                if(numRows==1)
                {
                    row=0;
                }
            }
            else
            {
                for(int i=0;i<numRows;i++)
                {
                    if(i==row)
                    {
                        vect[i].push_back(s[index]);      
                    }
                    else
                    {
                        vect[i].push_back(' ');
                    }
                }
                row--;
            }
        }
        string res = "";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<vect[i].size();j++)
            {
                if(vect[i][j]!=' ')
                {
                    res.push_back(vect[i][j]);
                }
            }
        }
        return res;
    }
};