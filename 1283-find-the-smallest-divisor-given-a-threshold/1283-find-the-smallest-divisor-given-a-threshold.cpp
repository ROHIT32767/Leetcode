class Solution {
public:
    int check(vector<int>& nums,int div){
        int sum = 0;
        int size = nums.size();
        for(int i=0;i<size;i++){
            sum += ceil((double)nums[i]/(double)div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int low = 1;
        long long int high = 1e18;
        int size = nums.size();
        long long int MIN = INT_MAX;
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(check(nums,mid)<=threshold){
                high = mid-1;
                MIN = min(MIN,mid);
            }   
            else{
                low = mid+1;
            }
        }
        return MIN;
    }
};