class Solution {
public:
    typedef long long int INT;
    int evalRPN(vector<string>& tokens) {
        stack<INT> num;
        stack<string> op;
        INT size = tokens.size();
        for(int i=0;i<size;i++)
        {
            string s = tokens[i];
            if(s=="+" || s=="-" || s=="*" || s=="/")
            {
                op.push(s);
                INT top1 = num.top();
                num.pop();
                INT top2 = num.top();
                num.pop();
                string top = op.top();
                op.pop();
                if(top=="+")
                {
                    num.push(top1+top2);
                }
                else if(top=="-")
                {
                    num.push(top2-top1);
                }
                else if(top=="*")
                {
                    num.push(top1*top2);
                }
                else if(top=="/")
                {
                    num.push(top2/top1);
                }
            }
            else
            {
                num.push(stoi(s));
            }
        }
        return num.top();
    }
};