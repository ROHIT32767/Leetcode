class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> M;
        for(int i=0;i<arr.size();i++){
            M[arr[i]]+=1;
        }
        set<int> S;
        for(auto i:M){
            int size_1 = S.size();
            S.insert(i.second);
            if(S.size()==size_1){
                return false;
            }
        }
        return true;
    }
};