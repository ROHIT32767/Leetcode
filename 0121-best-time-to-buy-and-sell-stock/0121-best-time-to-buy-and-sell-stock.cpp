class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> prefix_min(size,-1);
        prefix_min[0] = prices[0];
        for(int i=1;i<size;i++){
            prefix_min[i] = min(prices[i],prefix_min[i-1]);
        }
        int MAX = 0;
        for(int i=0;i<size;i++){
            MAX = max(MAX,prices[i]-prefix_min[i]);
        }
        return MAX;
    }
};