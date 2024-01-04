class Solution {
public:
    void merge_array(vector<int>& nums,int low,int mid,int high)
    {
        int size = high-low+1;
        vector<int> res(size,-1);
        int index = 0;
        int index1 = low;
        int index2 = mid+1;
        while(index1<=mid && index2<=high)
        {
            if(nums[index1]<=nums[index2])
            {
                res[index] = nums[index1];
                index++;
                index1++;
            }
            else{
                res[index] = nums[index2];
                index++;
                index2++;
            }
        }
        while(index1<=mid)
        {
            res[index] = nums[index1];
            index++;
            index1++;
        }
        while(index2<=high)
        {
            res[index] = nums[index2];
            index++;
            index2++;
        }
        for(int i=0;i<size;i++)
        {
            nums[i+low] = res[i];
        }
    }
    void merge(int start,int end,vector<int>& nums)
    {
        if(start<end)
        {
            int mid = start + (end-start)/2;
            merge(start,mid,nums);
            merge(mid+1,end,nums);
            merge_array(nums,start,mid,end);
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        merge(0,nums.size()-1,nums);
        return nums;
    }
};