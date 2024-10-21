typedef long long int INT;
class Solution {
public:
    vector<vector<int>> find(vector<int>& nums,INT target,int index){
        INT start = index+1;
        vector<vector<int>> ans;
        int end = nums.size()-1;
        INT prev_start = INT_MAX;
        INT prev_end = INT_MIN;
        while(end<nums.size() && start<end && start>index){
            INT current_sum = nums[start]+nums[end];
            if(current_sum==target){
                vector<int> temp;
                if(prev_start==nums[start] && prev_end==nums[end]){
                    start++;
                    continue;
                }
                temp.push_back(nums[start]);
                temp.push_back(nums[end]);
                prev_start = nums[start];
                prev_end = nums[end];
                ans.push_back(temp);
                start++;
            }
            else if(current_sum>target){
                end--;
            }
            else{
                start++;
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums,int index,INT target) {
       vector<vector<int>> ans;
       for(int i=index+1;i<nums.size()-2;i++){
           if(i>(index+1) && nums[i]==nums[i-1]){
               continue;
           }
           vector<vector<int>> temp = find(nums,INT(target-nums[i]),i);
           if(temp.size()==0){
               continue;
           }
           for(int j=0;j<temp.size();j++){
               vector<int> T;
               T.push_back(nums[i]);
               T.push_back(temp[j][0]);
               T.push_back(temp[j][1]);
               ans.push_back(T);
           }
       }
       return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4){
            vector<vector<int>> res;
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
           if(i>0 && nums[i]==nums[i-1]){
               continue;
           }
           vector<vector<int>> temp = threeSum(nums,i,INT(target-nums[i]));
           if(temp.size()==0){
               continue;
           }
           for(int j=0;j<temp.size();j++){
               vector<int> T;
               T.push_back(nums[i]);
               T.push_back(temp[j][0]);
               T.push_back(temp[j][1]);
               T.push_back(temp[j][2]);
               ans.push_back(T);
           }
       }
       return ans;
    }
};