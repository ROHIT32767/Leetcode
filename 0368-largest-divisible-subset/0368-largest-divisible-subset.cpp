class Solution {
public:
    typedef long long int INT;
    INT max(INT A,INT B){
        return A>B ? A:B;
    }
    int recursion(int index,vector<int>& dp,vector<int>& vect,vector<int>& prev){
        INT MAX = 1;
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=0;i<index;i++){
            if(vect[index]%vect[i]==0)
            {
                INT value = recursion(i,dp,vect,prev)+1;
                if(value>MAX){
                    prev[index]=i;
                    MAX = value;
                }
            }
        }
        return dp[index]=MAX;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        vector<int> dp(size,-1);
        vector<int> prev(size,-1);
        for(int i=0;i<size;i++)
        {
            recursion(i, dp, nums, prev);
        }
        int max_index = 0;
        INT MAX = 1;
        for(int i=0;i<size;i++){
            if(dp[i]>MAX){
                MAX = dp[i];
                max_index = i;
            }
        }
        vector<int> ans;
        while(max_index!=-1){
            ans.push_back(nums[max_index]);
            max_index = prev[max_index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};