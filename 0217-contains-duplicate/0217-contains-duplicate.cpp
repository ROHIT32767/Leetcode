class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> M;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            M[nums[i]]+=1;
        }
        int flag=0;
        for(auto i:M)
        {
            if(i.second>1)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            return false;
        }
        return true;
    }
};