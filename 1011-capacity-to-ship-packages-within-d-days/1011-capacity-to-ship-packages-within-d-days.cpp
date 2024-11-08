class Solution {
public:
    int day(vector<int>& nums,int cap){
        int ans = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum>cap){
                ans++;
                sum = nums[i];
            }
        }
        return ans+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int high = 0;
        int size = weights.size();
        int max_weight = weights[0];
        for(int i=0;i<size;i++){
            high += weights[i];
            max_weight = max(max_weight,weights[i]);
        }
        low = max_weight;
        int MIN = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(day(weights,mid)<=days){
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