class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> M;
        int size = nums.size();
        for(int i=0;i<size;i++){
            M[nums[i]]+=1;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto i:M){
            pq.push(make_pair(i.second,i.first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> vect;
        while(!pq.empty()){
            vect.push_back(pq.top().second);
            pq.pop();
        }
        return vect;
    }
};