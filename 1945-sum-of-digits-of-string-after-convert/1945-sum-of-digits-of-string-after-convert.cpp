class Solution {
public:
    string get_sum(string s)
    {
        int size = s.size();
        int sum = 0;
        for(int i=0;i<size;i++){
            sum+= s[i]-48;
        }
        return to_string(sum);
    }
    int getLucky(string s, int k) {
        string num = "";
        for(int i=0;i<s.size();i++){
            num += to_string(int(s[i]-96));
        }
        for(int i=0;i<k;i++){
            num = get_sum(num);
        }
        return stoi(num);
    }
};