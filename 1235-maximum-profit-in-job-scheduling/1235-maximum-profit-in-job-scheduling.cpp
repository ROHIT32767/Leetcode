class Solution {
public:
int binarySearch(const vector<pair<pair<int,int>,int>>& vect, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vect[mid].first.first <= key) {
            if (mid == right || vect[mid + 1].first.first > key) {
                return mid;
            } else {
                left = mid + 1;
            }
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int highestindex(vector<pair<pair<int,int>,int>>& vect, int index) {
    int starttime = vect[index].first.second;
    return binarySearch(vect, 0, index - 1, starttime);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>> vect;
        int size = profit.size();
        for(int i=0;i<size;i++)
        {
            vect.push_back(make_pair(make_pair(endTime[i],startTime[i]),profit[i]));
        }
        sort(vect.begin(),vect.end());
        vector<int> opt(size+1,0);
        for(int i=1;i<=size;i++)
        {
            opt[i] = max(vect[i-1].second+opt[highestindex(vect,i-1)+1],opt[i-1]);
        }
        return opt[size];
    }
};