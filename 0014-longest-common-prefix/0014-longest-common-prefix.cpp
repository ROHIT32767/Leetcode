class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string res = "";
        int size = strs.size();
        int MAX = strs[0].size();
        for(int i=1;i<strs.size();i++){
            int temp = strs[i].size();
            MAX = max(MAX,temp);
        }
        for(int j=0;j<MAX;j++){
            char ch = strs[0][j];
            for(int i=1;i<size;i++){
                if(ch!=strs[i][j]){
                    return res;
                }
            }
            res.push_back(ch);
        }
        return res;
        
    }
};