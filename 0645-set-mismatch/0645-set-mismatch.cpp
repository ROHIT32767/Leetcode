class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> S;
        int repeated_num = -1;
        int vector_sum = 0;
        for(int i=0;i<nums.size();i++){
            vector_sum += nums[i];
            int initial_size = S.size();
            S.insert(nums[i]);
            if(S.size()==initial_size){
                repeated_num = nums[i];
                vector_sum -= nums[i];
            }
        }
        int missing_num = nums.size()*(nums.size()+1);
        missing_num /= 2;
        return vector<int>{repeated_num,missing_num-vector_sum};
    }
};