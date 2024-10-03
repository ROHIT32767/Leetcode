typedef long long INT;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        if(nums.size()==0){
            return -1;
        }
        map<INT,INT> rem;
        vector<int> prefix;
        rem[nums[0]%p] = 0;
        INT total_sum = 0;
        for(INT i=0;i<nums.size();i++){
            total_sum += nums[i];
            total_sum%=p;
            prefix.push_back(total_sum);
        }
        INT MIN = nums.size();
        for(int i=1;i<nums.size();i++){
            INT new_rem = prefix[i]%p;
            INT val = (p+(prefix[i])%p-(total_sum)%p)%p;
            if(rem.find(val)==rem.end()){
                rem[new_rem] = i;
            }
            else{
                INT index = rem[val];
                INT new_min = (i-index);
                MIN = min(MIN,new_min);
                rem[new_rem] = i;
            }
        }
        if(total_sum%p==0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if((total_sum-prefix[i])%p==0){
                MIN = min(MIN,INT(i+1));
            }
        }
        if(MIN == nums.size()){
            return -1;
        }
        return MIN;
    }
};