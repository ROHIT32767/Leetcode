class Solution {
public:
    bool check(unordered_map<int,int>& M,int k){
        int MAX = 0;
        int count = 0;
        for(auto i:M){
            MAX = max(MAX,i.second);
            count += i.second;
        }
        if(count-MAX<=k){
            return true;
        }
        return false;
        
    }
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        unordered_map<int,int> M;
        int MAX = 0;
        while(j<s.size()){
            M[s[j]]+=1;
            if(check(M,k)){
                MAX = max(MAX,j-i+1);
            }
            else{
                M[s[i]] -=1;
                i++;
            }
            j++;
        }
        return MAX;
    }
};