class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i+=3){
            if(abs(nums[i]-nums[i+2])<=k){
                vector<int> vect = {nums[i],nums[i+1],nums[i+2]};
                ans.push_back(vect);
            }
            else{
                return vector<vector<int>> {};
            }
        }
        return ans;
    }
};