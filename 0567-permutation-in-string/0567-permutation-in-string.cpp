class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()){
            return false;
        }
        vector<int> freq(26,0);
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']+=1;
        }
        vector<int> F(26,0);
        int i=0;
        int j=0;
        while(i<s2.size() && j<s2.size()){
            F[s2[j]-'a']+=1;
            if(j-i+1==s1.size()){
                bool flag = true;
                for(int k=0;k<26;k++){
                    if(freq[k]!=F[k]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
            if(j-i+1<s1.size()){
                j++;
            }
            else{
                F[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};