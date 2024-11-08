class Solution {
public:
    int check(vector<int>& vect,int k,int day){
        int size = vect.size();
        int ans = 0;
        int count = 0;
        for(int i=0;i<size;i++){
            if(vect[i]<=day){
                count++;
                if(count==k){
                    ans++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        if((long long)k*(long long)m>size){
            return -1;
        }
        int high = 0;
        for(int i=0;i<size;i++){
            high = max(high,bloomDay[i]);
        }
        int low = 1;
        int MIN = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(bloomDay,k,mid)>=m){
                MIN = min(mid,MIN);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return MIN;
    }
};