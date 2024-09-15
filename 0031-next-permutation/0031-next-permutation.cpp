class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int index = -1;
        for(int i=0;i<size-1;i++){
            if(nums[i]<nums[i+1]){
                index = i;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int larger_element = index;
        for(int i=index+1;i<size;i++){
            if(nums[index]<nums[i]){
                larger_element = i;
            }
        }
        if(index==size-1){
            return;
        }
        swap(nums[index],nums[larger_element]);
        reverse(nums.begin()+index+1,nums.end());
    }
};