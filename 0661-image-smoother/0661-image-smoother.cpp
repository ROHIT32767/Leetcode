class Solution {
public:
    typedef long long int INT;
    INT convolution(INT row , INT column , vector<vector<int>>& img)
    {
        INT count = 0;
        INT sum = 0;
        for(int i=row-1;i<row+2;i++)
        {
            for(int j=column-1;j<column+2;j++)
            {
                if(i>=0 && i<img.size() && j>=0 && j<img[0].size())
                {
                    count++;
                    sum+=img[i][j];
                }
            }
        }
        return sum/count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> vect(img.size(),vector<int>(img[0].size(),0));
        for(int i=0;i<img.size();i++)
        {
            for(int j=0;j<img[0].size();j++)
            {
                vect[i][j]=convolution(i,j,img);
            }
        }
        return vect;
    }
};