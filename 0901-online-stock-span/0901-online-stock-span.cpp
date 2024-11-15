class StockSpanner {
public:
    stack<pair<int,int>> S;
    int count = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!S.empty() && S.top().first<=price){
            S.pop();
        }
        int val = 0;
        if(!S.empty()){
            val = count-S.top().second;
        }
        else{
            val = count+1;
        }
        S.push(make_pair(price,count));
        count++;
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */