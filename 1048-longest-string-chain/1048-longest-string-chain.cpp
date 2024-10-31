class Solution {
public:
    static bool compare(string &s1,string &s2)
    {
        return s1.size() < s2.size();
    }
    bool check(string wordA,string wordB){
        if(wordA.size()+1!=wordB.size()){
            return false;
        }
        int size1 = wordA.size();
        int size2 = wordB.size();
        int count = 0;
        int index1 = 0;
        for(int index2=0;index1<size1,index2<size2;index2++){
            if(wordA[index1]!=wordB[index2]){
                count++;
                continue;
            }
            index1++;
        }
        return count<=1 ? true:false;
    }
    int longestStrChain(vector<string>& words) {
        int size = words.size();
        sort(words.begin(),words.end(),compare);
        vector<int> dp(size,1);
        int MAX = 1;
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(check(words[j],words[i])){
                    dp[i] = max(dp[i],1+dp[j]);
                    MAX = max(MAX,dp[i]);
                }
            }
        }
        return MAX;
    }
};