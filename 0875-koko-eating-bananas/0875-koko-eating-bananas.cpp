class Solution {
public:
    int count(vector<int>& piles,long long int k,int h){
        int ans = 0;
        for(int i=0;i<piles.size();i++){
            ans += ceil((double)piles[i]/(double)k);
            if(ans>h){
                return ans;
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low = 1;
        long long int high = 1e18;
        long long int MIN = INT_MAX;
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(count(piles,mid,h)<=h){
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