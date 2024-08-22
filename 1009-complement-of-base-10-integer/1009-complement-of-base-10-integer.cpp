class Solution {
public:
    int bitwiseComplement(int n) {
        int num = n;
        int max_bit = 0;
        for(int i=31;i>=0;i--){
            int bit = num & (1 << i);
            if(bit){
                max_bit = i;
                break;
            }
        }
        for(int i=0;i<=max_bit;i++){
            int bit = num & (1 << i);
            if(bit){
                num = num & ~(1<<i);
            }
            else{
                num = num | (1<<i);
            }
        }
        return num;
    }
};