class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> vect;
        for(int i=1;i<intervals.size();i++){
            if(start==intervals[i][0]){
                end = intervals[i][1];
            }
            else if(intervals[i][0]>end){
                vect.push_back(vector<int>{start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else{
                end = max(end,intervals[i][1]);
            }
        }
        vect.push_back(vector<int>{start,end});
        return vect;
    }
};