class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        long long int rolls_sum = 0;
        for(int i=0;i<m;i++){
            rolls_sum += rolls[i];
        }
        long long int total_sum = mean*(m+n);
        int rem = total_sum - rolls_sum;
        long long int each = rem/n;
        if(rem<=0 || each<=0 || each>6){
            vector<int> vect;
            return vect;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(each);
        }
        rem-= each*n;
        if(rem<=0){
            return res;
        }
        bool flag = false;
        for(int i=0;i<n;i++){
            int add = min(6-res[i],rem);
            res[i]+= add;
            if(res[i]<=0 || res[i]>6){
                flag = true;
                break;
            }
            rem-= add;
            if(rem<=0){
                break;
            }
        }
        if(rem>0 || flag){
            vector<int> vect;
            return vect;
        }
        return res;
    }
};