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
    long long gcd(long long a, long long b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b); 
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        DSU DS(nums.size());
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<int> first(m+1,-1);
        for (int i = 0; i < n; ++i) {
            for (int prime = 2; prime * prime <= nums[i]; ++prime) {
                if (nums[i] % prime != 0)
                    continue;
                
                if (first[prime] != -1) 
                    DS.Union(first[prime], i);
                else
                    first[prime] = i;
                
                while (nums[i] % prime == 0) 
                    nums[i] /= prime;
            }
            if (nums[i] > 1) {
                if (first[nums[i]] != -1) 
                    DS.Union(first[nums[i]], i);
                else 
                    first[nums[i]] = i;
            }
            
        }
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            if(DS.find(i)!=DS.find(0)){
                return false;
            }
        }
        return true;
    }
};