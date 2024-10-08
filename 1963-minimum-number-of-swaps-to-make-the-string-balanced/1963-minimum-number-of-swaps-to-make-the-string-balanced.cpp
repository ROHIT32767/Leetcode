class Solution {
public:
    int minSwaps(string s) {
        stack<char> S;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                if(!S.empty()){
                    S.pop();
                }
                else{
                    count++;
                }
            }
            else{
                S.push('[');
            }
        }
        return (count+1)/2;
    }
};