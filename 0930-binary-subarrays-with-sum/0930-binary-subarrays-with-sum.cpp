class Solution {
public:
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