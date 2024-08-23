#include <string>
class Solution {
public:
    typedef long long ll;
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    ll findlcm(vector<int>& arr)
    {
        int n = arr.size();
        ll ans = arr[0];
        for (int i = 1; i < n; i++)
            ans = (((arr[i] * ans)) /
                    (gcd(arr[i], ans)));
        return ans;
    }
    void reduceFraction(int& x, int& y)
    {
        int d;
        d = __gcd(x, y);

        x = x / d;
        y = y / d;
        return;
    }
    string fractionAddition(string expression) {
        int sign = 1;
        int flip = 0;
        int size = expression.size();
        vector<int> numerator;
        vector<int> denominator;
        string s = "";
        for(int i=0;i<size;i++){
            cout << "s is " << s << endl;
            char ch = expression[i];
            if(ch=='+'){
                if(s!=""){
                    int num = stoi(s);
                    if(flip){
                        denominator.push_back(sign*num);
                        flip = 1-flip;
                    }
                    else{
                        numerator.push_back(sign*num);
                    }
                    s = "";
                }
                sign = 1;
            }
            else if(ch=='-'){
                if(s!=""){
                    int num = stoi(s);
                    if(flip){
                        denominator.push_back(sign*num);
                        flip = 1-flip;
                    }
                    else{
                        numerator.push_back(sign*num);
                    }
                    s = "";
                }
                sign = -1;
            }
            else if(ch=='/'){
                if(s!=""){
                    int num = stoi(s);
                    if(flip){
                        denominator.push_back(sign*num);
                        flip = 1-flip;
                    }
                    else{
                        numerator.push_back(sign*num);
                    }
                    
                    s = "";
                    sign = 1;
                }
                flip = 1-flip;
            }
            else{
                s.push_back(ch);
            }
        }
        int num = stoi(s);
        denominator.push_back(sign*num);
        int lcm = findlcm(denominator);
        cout << numerator.size() << " " << denominator.size() << endl;
        cout << "lcm is " << lcm << endl;
        cout << "Numerator Array" << endl;
        for(int i=0;i<numerator.size();i++){
            cout << numerator[i] << " ";
        }
        cout << endl;
        cout << "Denominator Array" << endl;
        for(int i=0;i<denominator.size();i++){
            cout << denominator[i] << " ";
        }
        cout << endl;
        int sum = 0;
        for(int i=0;i<numerator.size();i++){
            sum += numerator[i]*(lcm/denominator[i]);
        }
        int x = sum;
        int y = lcm;
        if(sum==0){
            return "0/1";
        }
        reduceFraction(x,y);
        if((x<0 && y<0) || (x>0 && y<0)){
            x=-x;
            y=-y;
        }
        string res = "";
        res+= to_string(x);
        res+="/";
        res+= to_string(y);
        return res;
    }
};