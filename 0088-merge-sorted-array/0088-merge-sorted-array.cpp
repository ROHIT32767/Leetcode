class Solution {
public:
    typedef long long int INT;
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        INT index = m+n-1;
        INT index1 = m-1;
        INT index2 = n-1;
        while(index1>=0 & index2>=0){
            if(nums1[index1]>nums2[index2]){
                nums1[index] = nums1[index1];
                index1--;
                index--;
            }
            else{
                nums1[index] = nums2[index2];
                index2--;
                index--;
            }
        }
        while(index1>=0)
        {   
            nums1[index] = nums1[index1];
            index1--;
            index--;
        }
        while(index2>=0){
            nums1[index] = nums2[index2];
            index2--;
            index--;
        }
    }
};