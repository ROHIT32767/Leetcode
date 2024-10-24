class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int>& nums,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            backtrack(ans,nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans,nums,0);
        return ans;
    }
};