class Solution {
public:
    int solve(string& s,int k){
        int a = 0;
        int b = 0;
        int c = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        while(j<s.size()){
            if(s[j]=='a'){
                a++;
            }
            if(s[j]=='b'){
                b++;
            }
            if(s[j]=='c'){
                c++;
            }
            while(a && b && c){
                if(s[i]=='a'){
                    a--;
                }
                if(s[i]=='b'){
                    b--;
                }
                if(s[i]=='c'){
                    c--;
                }
                i++;
            }
            count+= j-i+1;
            j++;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        long long int size = s.size();
        return (size*(size+1))/2 - solve(s,2);
    }
};