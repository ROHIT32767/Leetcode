class Solution {
public:
    int maximumSwap(int num) {
        string s1 = to_string(num);
        string s = s1;
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        bool flag = 0;
        int index = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s1[i]){
                flag = 1;
                index = i;
                break;
            }
        }
        if(!flag){
            return num;
        }
        char ch = s[index];
        int last_index = -1;
        for(int i=0;i<s.size();i++){
            if(s1[i]==ch){
                last_index = i;
            }
        }
        char temp = s1[index];
        s1[index] = ch;
        s1[last_index] = temp;
        return stoi(s1);
    }
};