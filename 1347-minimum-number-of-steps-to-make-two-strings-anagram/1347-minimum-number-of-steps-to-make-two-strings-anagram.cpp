class Solution {
public:
    int minSteps(string s, string t) {
        map<int,int> M1,M2;
        for(int i=0;i<s.size();i++){
            M1[s[i]]+=1;
        }
        for(int j=0;j<t.size();j++){
            M2[t[j]]+=1;
        }
        int count = 0;
        for(auto i:M1){
            if(i.second<M2[i.first]){
                continue;
            }
            count+=abs(i.second-M2[i.first]);
        }
        return count;
    }
};