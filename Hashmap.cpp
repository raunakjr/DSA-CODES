class MyHashMap {
    vector<vector<pair<int,int>>>v;
    int bl;

    int hash(int key)
    {
        return key%bl;
    }
    
    public:
  
    MyHashMap() {
        bl=10001;
        v=vector<vector<pair<int,int>>>(bl,vector<pair<int,int>>{}); 
    }
    
    void put(int key, int value) {
        int idx=hash(key);
        bool f=0;
        for(int i=0;i<v[idx].size();i++)
        {
            if(v[idx][i].first==key)
            {
                v[idx][i].second=value;
                f=1;
                break;
            }
        }
        if(!f) v[idx].push_back({key,value});
    }
    
    int get(int key) {
        int idx=hash(key);
        bool f=0;
        for(int i=0;i<v[idx].size();i++)
        {
            if(v[idx][i].first==key)
            {
                return v[idx][i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
         int idx=hash(key);
        bool f=0;
        for(int i=0;i<v[idx].size();i++)
        {
            if(v[idx][i].first==key)
            {
                 swap(v[idx][i],v[idx].back());
                 v[idx].pop_back();
                 return ;
            }
        }
        
    }
};

