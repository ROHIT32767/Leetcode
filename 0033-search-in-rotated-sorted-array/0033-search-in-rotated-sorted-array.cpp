class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = 0;
        int low = 0;
        int high = nums.size()-1;
        int size = nums.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            int prev = (size+mid-1)%size;
            int next = (mid+1+size)%size;
            if(nums[mid]>nums[next]){
                index = (mid+1+size)%size;
                break;
            }
            else if(nums[mid]<nums[next] && nums[mid]<nums[prev]){
                index = mid;
                break;
            }
            else if(nums[low]<=nums[mid]){
                low = (mid+1);
            }
            else if(nums[mid]<=nums[high]){
                high = mid-1;
            }
        }
        low = 0;
        high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int temp = (mid+index)%size;
            if(nums[temp]==target){
                return temp;
            }
            else if(nums[temp]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};