class Solution {
public:
    typedef long long INT;
    INT max(INT A,INT B){
        return A<B ? B: A;
    }
    INT min(INT A,INT B){
        return A<B ? A:B;
    }
    int maxProfit(vector<int>& prices) {
        INT MIN = INT_MAX;
        MIN = prices[0];
        INT MAX = 0;
        for(int i=1;i<prices.size();i++){
            MAX = max(MAX,prices[i]-MIN);
            MIN = min(MIN,prices[i]);
        }
        return MAX;
    }
};