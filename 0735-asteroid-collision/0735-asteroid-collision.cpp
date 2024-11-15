class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> S;
        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!S.empty() && asteroid < 0 && S.top() > 0) {
                if (abs(S.top()) > abs(asteroid)) {
                    destroyed = true;
                    break;
                } 
                else if (abs(S.top()) == abs(asteroid)) {
                    S.pop();
                    destroyed = true;
                    break;
                }
                else {
                    S.pop();
                }
            }
            if (!destroyed) {
                S.push(asteroid);
            }
        }
        vector<int> result(S.size());
        for (int i = S.size() - 1; i >= 0; --i) {
            result[i] = S.top();
            S.pop();
        }
        return result;
    }
};