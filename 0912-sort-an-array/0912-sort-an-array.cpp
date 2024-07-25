class Solution {
public:
    
    
void merge_array(vector<int>& nums,int low,int mid,int high)
{
    int index1 = low;
    int index2 = mid+1;
    vector<int> res;
    while(index1<=mid && index2<=high){
        if(nums[index1]<nums[index2]){
            res.push_back(nums[index1]);
            index1++;
        }
        else{
            res.push_back(nums[index2]);
            index2++;
        }
    }
    while(index1<=mid){
        res.push_back(nums[index1]);
        index1++;
    }
    while(index2<=high)
    {
        res.push_back(nums[index2]);
        index2++;
    }
    for(int i=0;i<high-low+1;i++){
        nums[i+low] = res[i];
    }
}

void merge(int low,int high,vector<int>& nums){
    int mid = low+(high-low)/2;
    if(low<high){
        merge(low,mid,nums);
        merge(mid+1,high,nums);
        merge_array(nums,low,mid,high);
    }
}
vector<int> sortArray(vector<int>& nums) {
        merge(0,nums.size()-1,nums);
        return nums;
}
};