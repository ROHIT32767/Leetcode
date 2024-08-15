class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int twenties = 0;
        for(int i=0;i<bills.size();i++){
            int val = bills[i];
            if(val==5){
                fives++;
            }
            else if(val==10){
                tens++;
            }
            else{
                twenties++;
            }
            int rem = val-5;
            if(rem==5){
                if(fives){
                    fives--;
                }
                else{
                    return false;
                }
            }
            else if(rem==15){
                if(tens>=1 && fives>=1)
                {
                    tens--;
                    fives--;
                }
                else if(fives>=3){
                    fives-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};