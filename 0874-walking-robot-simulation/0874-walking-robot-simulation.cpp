class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> set;
        int x = 0, y = 0, maxDist = 0;
        pair<int, int> direction = {0, 1};
        for(auto i : obstacles){
            string temp = to_string(i[0])+"_"+to_string(i[1]);
            set.insert(temp);
        }
        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == -2) 
                direction = {-direction.second, direction.first};
            else if(commands[i] == -1)
                direction = {direction.second, -direction.first};
            else { 
                for(int step = 0; step < commands[i]; step++) {
                    int tempX = x + direction.first, tempY = y + direction.second;
                    string temp = to_string(tempX) + "_" + to_string(tempY);
                    if(set.find(temp) != set.end())
                        break;
                    x = tempX;
                    y = tempY;
                }
            }
            maxDist = max(maxDist, x*x + y*y);
        }
        return maxDist;
    }
};