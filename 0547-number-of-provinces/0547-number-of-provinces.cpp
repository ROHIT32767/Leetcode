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
};
class Solution {
public:
    void DFS(int node,vector<int>& vis ,vector<int> vect[])
    {
        vis[node]=1;
        for(auto i:vect[node])
        {
            if(!vis[i])
            {
                DFS(i,vis,vect);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int rows = isConnected.size();
        int columns = rows;
        DSU DS(rows);
        for(int i=0;i<rows;i++)
        {
            for(int j=i+1;j<rows;j++)
            {
                if(isConnected[i][j])
                {
                    if(DS.find(i)!=DS.find(j))
                    {
                        DS.Union(i,j);
                    }
                }
            }
        }
        set<int> S;
        int count = 0;
        for(int i=0;i<rows;i++)
        {
            S.insert(DS.find(i));
        }
        return S.size();
    }
};