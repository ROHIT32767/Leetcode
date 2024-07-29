class Solution {
public:
    typedef long long INT;
    template <typename T> int sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }
    int numTeams(vector<int>& rating) {
        int size = rating.size();
        INT count = 0;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                for(int k=j+1;k<size;k++){
                    INT sign1 = sgn(rating[j]-rating[i]);
                    INT sign2 = sgn(rating[k]-rating[j]);
                    INT val = sign1*sign2;
                    if(val>0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};