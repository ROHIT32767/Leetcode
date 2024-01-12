class Solution {
public:
    int vowel_count(string s){
        set<char> S = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(S.find(s[i])!=S.end()){
                count++;
            }
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        return vowel_count(s.substr(0,s.size()/2))==vowel_count(s.substr(s.size()/2,s.size()/2));
    }
};