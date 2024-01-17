class Solution {
public:
    void backtrack(vector<int>& nums,int start,int end,set<vector<int>>& ans)
    {
        if(start==end)
        {
            ans.insert(nums);
            return;
        }
        for(int i=start;i<=end;i++)
        {
            int temp1 = nums[start];
            int temp2 = nums[i];
            nums[start]=nums[i];
            nums[i]=temp1;
            backtrack(nums,start+1,end,ans);
            nums[start]=temp1;
            nums[i]=temp2;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        backtrack(nums,0,nums.size()-1,ans);
        vector<vector<int>> res;
        res.assign(ans.begin(),ans.end());
        return res;
    }
};