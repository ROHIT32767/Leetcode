class Solution {
public:
    bool check(map<char,int>& M){
        for(auto i:M){
            if(i.second>1){
                return false;
            }
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1){
            return s.size();
        }
        map<char,int> M;
        int i=0, j=1;
        M[s[0]]+=1;
        int MAX = 1;
        while(j<s.size() && i<j){
            M[s[j]]+=1;
            if(check(M)){
                MAX = max(MAX,j-i+1);
                j++;
            }
            else{
                M[s[i]]-=1;
                i++;
                j++;
            }
        }
        return MAX;
    }
};