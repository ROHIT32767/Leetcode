class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int size = matches.size();
        map<int,int> M;
        for(int i=0;i<size;i++){
            M[matches[i][1]]+=1;
            if(M.find(matches[i][0])==M.end()){
                M[matches[i][0]]=0;
            }
        }
        vector<vector<int>> result;
        vector<int> not_lost;
        vector<int> lost_one;
        for(auto i:M){
            if(i.second==0){
                not_lost.push_back(i.first);
            }
            else if(i.second==1){
                lost_one.push_back(i.first);
            }
        }
        result.push_back(not_lost);
        result.push_back(lost_one);
        return result;
    }
};