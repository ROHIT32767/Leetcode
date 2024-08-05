class Solution {
public:
    typedef long long int INT;
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> M;
        for(int i=0;i<arr.size();i++){
            M[arr[i]]+=1;
        }
        INT count = 0;
        for(int i=0;i<arr.size();i++){
            if(M[arr[i]]==1){
                if(count==k-1){
                    return arr[i];
                }
                count++;
            }
            M[arr[i]]=0;
        }
        return "";
    }
};