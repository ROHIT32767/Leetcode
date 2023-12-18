class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        if(nums[0]*nums[size-1]>0)
        {
            return abs(nums[size-1]*nums[size-2]-nums[1]*nums[0]);
        }
        else
        {
            return max(nums[0]*nums[1]-nums[2]*nums[size-1],nums[size-1]*nums[size-2]-nums[0]*nums[size-3]);
        }
    }
};