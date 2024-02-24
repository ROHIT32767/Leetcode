class DSU{
    vector<int> parent,size;
public:
    DSU(int n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int u , int v)
    {
        int pu = find(u);
        int pv = find(v);
        if(pu==pv)
        {
            return;
        }
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
    void reset(int x){
        parent[x]=x;
    }
};
class Solution {
public:
    static bool compareThirdElement(const vector<int>& a, const vector<int>& b) {
        if(a[2]==b[2]){
            return a<b;
        }
        return a[2] < b[2]; 
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int size = n;
        DSU DS(n);
        DS.Union(0,firstPerson);
        sort(meetings.begin(),meetings.end(),compareThirdElement);
        vector<vector<int>> A = meetings;
        int len = meetings.size();
        int prev = -1;
        vector<int> ppl;
        for (int i = 0, M = A.size(); i < M; ) {
            ppl.clear();
            int time = A[i][2];
            for (; i < M && A[i][2] == time; ++i) {
                DS.Union(A[i][0], A[i][1]); 
                ppl.push_back(A[i][0]); 
                ppl.push_back(A[i][1]);
            }
            for (int n : ppl) { 
                if (DS.find(0)!=DS.find(n)) DS.reset(n); 
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(DS.find(0)==DS.find(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};