class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> vect;
        vector<int> temp;
        if(original.size()%n!=0 || original.size()/n!=m){
            vector<vector<int>> empty;
            return empty;
        }
        for(int i=0;i<original.size();i++){
            if(i%n==0){
                temp = {};
            }
            temp.push_back(original[i]);
            if(i%n==n-1){
                vect.push_back(temp);
            }
        }
        return vect;
    }
};