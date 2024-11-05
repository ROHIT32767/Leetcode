class Solution {
public:
    bool check(map<char,int>& S,map<char,int>& T){
        for(auto i:T){
            if(S[i.first]< i.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int> S;
        map<char,int> T;
        for(int i=0;i<t.size();i++){
            T[t[i]]+=1;
        }
        int i=0;
        int j=0;
        int min_i = -1;
        int min_j = -1;
        int MIN = s.size()+1;
        while(j<s.size()){
            S[s[j]]+=1;
            if(check(S,T)){
                if(j-i+1<MIN){
                    min_i = i;
                    min_j = j;
                }
                MIN = min(MIN,j-i+1);
                while(i<=j && check(S,T)){
                    if(j-i+1<MIN){
                        min_i = i;
                        min_j = j;
                    }
                    MIN = min(MIN,j-i+1);
                    S[s[i]]-=1;
                    i++;
                }
            }
            j++;
        }
        if(min_i==-1 && min_j==-1){
            return "";
        }
        cout << min_i << " " << min_j << endl;
        return s.substr(min_i,min_j-min_i+1);
    }
};