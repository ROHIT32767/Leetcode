class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        for(int i=31;i>=0;i--){
            int var1 = (start >> i) & 1;
            int var2 = (goal >> i) & 1;
            if(var1!=var2){
                count++;
            }
        }
        return count;
    }
};