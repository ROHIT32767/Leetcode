class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int size = arrays.size();
        vector<int> largest;
        for(int i=0;i<size;i++){
            largest.push_back(arrays[i][arrays[i].size()-1]);
        }
        sort(largest.begin(),largest.end());
        int large = largest[largest.size()-1];
        int MAX = 0;
        for(int i=0;i<arrays.size();i++){
            int val = arrays[i][0];
            int val1 = arrays[i][arrays[i].size()-1];
            if(val1==large){
                MAX = max(MAX,abs(val-largest[largest.size()-2]));
            }
            else{
                MAX = max(MAX,abs(val-large));
            }
        }
        return MAX;
    }
};