class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vect;
        if (numRows == 1)
        {
            vector<int> vect1{1};
            vect.push_back(vect1);
            return vect;
        }
        if (numRows == 2)
        {
            vector<int> vect1{1};
            vect.push_back(vect1);
            vector<int> vect2{1, 1};
            vect.push_back(vect2);
            return vect;
        }
        vector<int> vect1{1};
        vect.push_back(vect1);
        vector<int> vect2{1, 1};
        vect.push_back(vect2);
        for (int i = 2; i < numRows; i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < i; j++)
            {
                temp.push_back(vect[i-1][j-1] + vect[i-1][j]);
            }
            temp.push_back(1);
            vect.push_back(temp);
        }
        return vect;
    }
};