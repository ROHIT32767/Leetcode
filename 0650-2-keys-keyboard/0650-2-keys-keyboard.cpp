class Solution {
public:
    bool isPrime(int N)
    {
        if (N <= 1) {
            return false;
        }
        if (N <= 3) {
            return true;
        }
        if (N % 2 == 0 || N % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= N; i += 6) {
            if (N % i == 0 || N % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        if(n<=5){
            return n;
        }
        for(int i=2;i<n;i++){
            if(n%i==0 && isPrime(i)){
                return i+minSteps(n/i);
            }
        }
        return n;
    }
};