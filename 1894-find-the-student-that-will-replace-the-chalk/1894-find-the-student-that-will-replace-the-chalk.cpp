class Solution {
public:
    typedef long long int INT;
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<INT> prefix;
        prefix.push_back(chalk[0]);
        for(int i=1;i<chalk.size();i++){
            prefix.push_back(prefix[i-1]+chalk[i]);
        }
        INT size = chalk.size();
        INT total_sum = prefix[size-1];
        INT rem = k%total_sum;
        if(rem==0){
            return 0;
        }
        INT i = 0;
        while(rem>=chalk[i] && i<size){
            rem-=chalk[i];
            i++;
        }
        return i;
    }
};