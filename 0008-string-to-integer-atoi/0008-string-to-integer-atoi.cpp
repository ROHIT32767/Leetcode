class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int sign = 1;
        int found = 0;
        int valid = 0;
        string num = "";
        for(int i=0;i<size;i++)
        {
            int x = s[i];
            if(valid)
            {
                if(x<48 || x>57)
                {
                    break;
                }
                num.push_back(s[i]);
            }
            else
            {
                if(s[i]=='+' && !found)
                {
                    sign = 1;
                    found = 1;
                    valid = 1;
                }
                else if(s[i]=='-' && !found)
                {
                    sign=-1;
                    found = 1;
                    valid=1;
                }
                else if(x>=48 && x<=57)
                {
                    num.push_back(s[i]);
                    valid = 1;
                }
                else if(x!=32)
                {
                    valid = 0;
                    break;
                }
            }
        }
        cout << num << endl;
        if(!valid)
        {
            return 0;
        }
        string max="2147483647";
        string min="2147483648";
        int flag = 0;
        size = num.size();
        string y="";
        for(int i=0;i<size;i++)
        {
            if(num[i]!='0')
            {
                flag=1;
                y.push_back(num[i]);
            }
            else if(flag)
            {
                y.push_back(num[i]);
            }
        }
        cout << y << endl;
        if(!flag)
        {
            return 0;
        }
        // num = y;
        if(sign>0 && y.size()>max.size())
        {
            return 2147483647;
        }
        else if(sign > 0 && y>=max && y.size()==max.size())
        {
             return 2147483647;
        }
        else if(sign<0 && y.size()>min.size())
        {
            return -2147483648;
        }
        else if(sign<0 && y>=min && y.size()==max.size())
        {
            return -2147483648;
        }
        else
        {
            long long int sum = 0;
            size = y.size();
            for(int i=0;i<size;i++)
            {
                sum+=(y[size-1-i]-48)*pow(10,i);
            }
            return sign*sum;
        }
    }
};