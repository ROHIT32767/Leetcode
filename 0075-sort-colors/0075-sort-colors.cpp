class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int i=0;i<nums.size();i++){
            switch(nums[i]){
                case 0:
                    zero++;
                    break;
                case 1:
                    one++;
                    break;
                case 2:
                    two++;
                    break;
                default:
                    break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(zero){
                nums[i] = 0;
                zero--;
            }
            else if(!zero && one){
                nums[i] = 1;
                one--;
            }
            else if(!zero && !one && two){
                nums[i] = 2;
                two--;
            }
        }
    }
};