class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int zeroes = 0;
        int MAX = 0;
        while(j<nums.size()){
            zeroes = nums[j]==0 ? zeroes+1 : zeroes;
            if(zeroes<=k){
                MAX = max(MAX,j-i+1);
            }
            else{
                zeroes = nums[i]==0 ? zeroes-1 : zeroes;
                i++;
            }
            j++;
        }
        return MAX;
    }
};