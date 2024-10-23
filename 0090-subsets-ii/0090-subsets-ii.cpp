class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int>& nums,int index,vector<int>& current){
        ans.push_back(current);
        if(index>=nums.size()){
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            current.push_back(nums[i]);
            backtrack(ans,nums,i+1,current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(),nums.end());
        backtrack(ans,nums,0,current);
        return ans;
    }
};