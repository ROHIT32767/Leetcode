class Solution {
public:
        int min(int a , int b)
    {
        if(a<b)
        {
            return a;
        }
        return b;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            adj[i][i]=0;
        }
        int size = edges.size();
        for(int i=0;i<size;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u][v]=w;
            adj[v][u]=w;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX)
                    {
                        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                    }
                }
            }
        }
        int city = 0;
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int current = 0;
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]<=distanceThreshold)
                {
                    current++;
                }
            }
            if(current<=min)
            {
                min = current;
                city = i;
            }
        }
        return city;
    }
};