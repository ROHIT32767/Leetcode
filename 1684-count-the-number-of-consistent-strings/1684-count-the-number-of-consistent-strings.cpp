class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> S;
        for(int i=0;i<allowed.size();i++){
            S.insert(allowed[i]);
        }
        int count = 0;
        int size = words.size();
        for(int i=0;i<size;i++){
            string temp = words[i];
            set<char> T = S;
            for(int j=0;j<temp.size();j++){
                T.insert(temp[j]);
            }
            if(S==T){
                count++;
            }
        }
        return count;
    }
};