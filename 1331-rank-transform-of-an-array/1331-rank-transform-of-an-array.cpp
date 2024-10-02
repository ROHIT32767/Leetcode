class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0){
            return vector<int>();
        }
        vector<pair<int,int>> vect;
        for(int i=0;i<arr.size();i++){
            vect.push_back(make_pair(arr[i],i));
        }
        sort(vect.begin(),vect.end());
        int index = 1;
        map<int,int> M;
        M[vect[0].first] = 1;
        for(int i=1;i<vect.size();i++){
            if(vect[i].first!=vect[i-1].first){
                index++;
                M[vect[i].first] = index;
            }
        }
        vector<int> res(arr.size(),-1);
        for(int i=0;i<vect.size();i++){
            res[vect[i].second] = M[vect[i].first];
        }
        return res;
    }
};