class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int>& current,int current_sum,int index,int target,vector<int>& candidates){
        if(current_sum==target){
            ans.push_back(current);
            return;
        }
        if(current_sum>target){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            current.push_back(candidates[i]);
            current_sum+=candidates[i];
            backtrack(ans,current,current_sum,i+1,target,candidates);
            current.pop_back();
            current_sum-= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        int current_sum = 0;
        backtrack(ans,current,current_sum,0,target,candidates);
        return ans;
    }
};