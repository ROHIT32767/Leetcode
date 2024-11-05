class Solution {
public:
    int solve(vector<int>& nums,int goal){
        if(goal<0){
            return 0;
        }
        int i=0;
        int j=0;
        int sum = 0;
        int count = 0;
        while(j<nums.size()){
            sum += nums[j];
            if(sum>goal){
                sum-=nums[i];
                i++;
            }
            else{
                count+= j-i+1;
            }
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> M;
        int sum = 0;
        int count = 0;
        M[0] = 1;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            count+= M[sum-goal];
            M[sum]++;
        }
        return count;
    }
};