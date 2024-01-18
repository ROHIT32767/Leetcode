class Solution {
public:
    static bool customsort(pair<int,int> A,pair<int,int> B){
        if(A.first==B.first){
            return A.second > B.second;
        }
        return A.first < B.first;
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> range;
        for(int i=0;i<ranges.size();i++){
            int left = i-ranges[i] >=0 ? i-ranges[i] : 0;
            int right = i+ranges[i] <=n ? i+ranges[i] : n;
            range.push_back(make_pair(left,right));
        }
        sort(range.begin(),range.end(),customsort);
        for(int i=0;i<range.size();i++){
            cout << range[i].first << " " << range[i].second << endl;
        }
        int left = -1;
        int right = -1;
        int index = 0;
        if(range[0].first>0){
            return -1;
        }
        left = 0;
        right = range[0].second;
        index++;
        int num_taps = 1;
        while(right<n && index<range.size()){
            int max_right = right;
            bool flag = false;
            while(index<range.size()){
                if(range[index].first<=right){
                    max_right = max(max_right,range[index].second);
                    flag = true;
                    index++;
                }
                else{
                    break;
                }
            }
            if(!flag){
                return -1;
            }
            right = max_right;
            num_taps++;
        }
        if(right<n){
            return -1;
        }
        return num_taps;
    }
};