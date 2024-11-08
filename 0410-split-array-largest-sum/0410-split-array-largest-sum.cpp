class Solution {
public:
    int check(vector<int>& nums,int cap){
        int size = nums.size();
        int count = 0;
        int sum = 0;
        for(int i=0;i<size;i++){
            sum+= nums[i];
            if(sum>cap){
                count++;
                sum = nums[i];
            }
        }
        return count+1;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = -1;
        int high = 0;
        int size = nums.size();
        for(int i=0;i<size;i++){
            low = max(low,nums[i]);
            high += nums[i];
        }
        if(low==0){
            return 0;
        }
        int MIN = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(nums,mid)<=k){
                MIN = min(MIN,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return MIN;
    }
};