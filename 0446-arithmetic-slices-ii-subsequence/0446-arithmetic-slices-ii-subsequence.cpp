class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long long int,long long int>> vect(nums.size());
        int size = nums.size();
        long long int count = 0;
        for(int start=0;start<size;start++)
        {
            for(int end=0;end<start;end++)
            {
                long long int diff = (long long) nums[start]-nums[end];
                long long int num_count = vect[end].count(diff) ? vect[end][diff] : 0;
                vect[start][diff] += num_count+1LL;
                count+=num_count;
            }
        }
        return count;
    }
};