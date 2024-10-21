class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        long long int prev = INT_MAX;
        int count = 0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==prev){
                continue;
            }
            nums.push_back(nums[i]);
            prev = nums[i];
            count++;
        }
        reverse(nums.begin(),nums.end());
        return count;
    }
};