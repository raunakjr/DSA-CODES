class DSU
{
    private:
    vector<int>par;
    vector<int>size;
    public:
    DSU(int n)
    {
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            size[i]=1;
        }
    }

    void unionn(int u, int v)
    {
        u=findpar(u);
        v=findpar(v);
        if(u==v) return ;
        
        if(size[u]<size[v])
        {
            par[u]=v;
            size[v]+=1;
        }
        else
        {
            par[v]=u;
            size[u]+=1;
        }
    }
    int findpar(int i)
    {
            if(i==par[i]) return i;
            return par[i]=findpar(par[i]);
    }
};
