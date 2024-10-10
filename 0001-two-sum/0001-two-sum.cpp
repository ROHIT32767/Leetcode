class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vect;
        for(int i=0;i<nums.size();i++){
            vect.push_back(make_pair(nums[i],i));
        }
        sort(vect.begin(),vect.end());
        int start = 0;
        int end = nums.size()-1;
        while(start<end){
            int value = vect[start].first+vect[end].first;
            if(value==target){
                vector<int> temp;
                temp.push_back(vect[start].second);
                temp.push_back(vect[end].second);
                return temp;
            }
            else{
                if(value<target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return vector<int>();
    }
};