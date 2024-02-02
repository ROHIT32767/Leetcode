class Solution {
public:
    void recursion(string s,int low,int high,vector<int>& vect){
        int size = s.size();
        int num = stoi(s);
        if(num>=low && num<=high){
            vect.push_back(num);
        }
        else if(num>high){
            return;
        }
        int last = s[size-1]-'0';
        if(last==9){
            return;
        }
        char ch = '0'+last+1;
        s.push_back(ch);
        recursion(s,low,high,vect);
        s.pop_back();
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> vect;
        for(int i=1;i<10;i++){
            string s = to_string(i);
            recursion(s,low,high,vect);
        }
        sort(vect.begin(),vect.end());
        return vect;
    }
};