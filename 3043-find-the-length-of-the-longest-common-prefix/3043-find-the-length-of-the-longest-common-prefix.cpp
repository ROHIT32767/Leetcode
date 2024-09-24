class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string,int> M;
        for(int i=0;i<arr1.size();i++){
            for(int j=1;j<=to_string(arr1[i]).size();j++){
                M[to_string(arr1[i]).substr(0,j)]=1;
            }
        }
        int MAX = 0;
        for(int i=0;i<arr2.size();i++){
            for(int j=1;j<=to_string(arr2[i]).size();j++){
                if(M[to_string(arr2[i]).substr(0,j)]==1){
                    MAX = max(MAX,j);
                }
            }
        }
        return MAX;
    }
};