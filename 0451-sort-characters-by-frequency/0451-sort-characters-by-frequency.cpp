class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        map<char,int> M;
        for(int i=0;i<s.size();i++)
        {
            M[s[i]]+=1;
        }
        for(auto i:M){
            pq.push(make_pair(i.second,i.first));
        }
        string ans = "";
        while(pq.size())
        {
            pair<int,char> P = pq.top();
            for(int i=0;i<P.first;i++){
                ans.push_back(P.second);
            }
            pq.pop();
        }
        return ans;
    }
};