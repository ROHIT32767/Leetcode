class Solution {
public:
    bool check(vector<int>& arr,int target){
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        for(int i=1;;i++){
            if(!check(arr,i)){
                count++;
                if(count==k){
                    return i;
                }
            }
        }
    }
};