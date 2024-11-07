class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return vector<int>{-1,-1};
        }
        if(nums.size()==1){
            if(nums[0]==target){
                return vector<int>{0,0};
            }
            return vector<int>{-1,-1};
        }
        int low = 0;
        int high = nums.size()-1;
        int MIN = INT_MAX;
        int MAX = -1;
        vector<int> vect;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<=target){
                MAX = max(MAX,mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        low = 0;
        high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=target){
                MIN = min(MIN,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(MIN==INT_MAX){
            MIN = -1;
        }
        else{
            MIN = nums[MIN] != target ? -1 : MIN;
        }
        if(MAX!=-1){
            MAX = nums[MAX] != target ? -1 : MAX;
        }
        vect.push_back(MIN);
        vect.push_back(MAX);
        return vect;
    }
};