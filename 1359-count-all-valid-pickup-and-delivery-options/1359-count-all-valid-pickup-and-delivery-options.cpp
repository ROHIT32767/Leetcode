class Solution {
public:
    long long int MOD = 1000000007;
    long long int solve(int n)
    {
        long long int ans = (n*(n-1))/2;
        return ans%MOD;
    }
    int countOrders(int n) {
        long long int product = 1;
        for(int i=2;i<=2*n;i+=2)
        {
            product = product*solve(i);
            product%=MOD;
        }
        return product%MOD;
    }
};