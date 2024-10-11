class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<pair<int,int>,int>> vect;
        for(int i=0;i<times.size();i++){
            vect.push_back(make_pair(make_pair(times[i][0],times[i][1]),i));
        }
        sort(vect.begin(),vect.end());
        int index = 0;
        for(int i=0;i<times.size();i++){
            if(vect[i].second==targetFriend){
                break;
            }
            index++;
        }
        if(index==0){
            return 0;
        }
        vector<int> vis(times.size()+1,0);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        int chair_index = 0;
        for(int i=0;i<=index;i++){
            int t = vect[i].first.first;
            while(pq.size() && pq.top().first<=t){
                vis[pq.top().second] = 0;
                pq.pop();
            }
            chair_index = 0;
            while(vis[chair_index]){
                chair_index++;
            }
            pq.push(make_pair(vect[i].first.second,chair_index));
            vis[chair_index] = 1;
        }
        return chair_index;
    }
};