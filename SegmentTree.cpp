

#include <iostream>
#include<bits/stdc++.h>
using ll=long long;
using namespace std;



void f()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE
}
vector<pair<long long,long long>>seg;
void build(long long l, long long h, long long i, vector<long long>&arr)
{
    
    if(l==h) 
    {
         seg[i]={arr[l],1};
         return ;
        
    }
    
    long long m=(l+h)>>1;
    build(l,m,2*i+1,arr);
    build(m+1,h,2*i+2,arr);
    auto ls=seg[2*i+1];
    auto rs=seg[2*i+2];
    long long mini=min(ls.first,rs.first);
    long long cnt=0;
    if(ls.first==mini) cnt+=ls.second;
    if(rs.first==mini) cnt+=rs.second;
    seg[i]={mini,cnt};
}
pair<long long,long long> mini( long long i,long long left, long long right,long long l ,long long r)
    {
        if (right < l || left > r) return {INT_MAX,0};
        if (left <= l && r <= right) return seg[i];
       long long m=(l+r)/2;
      auto ls=mini(2*i+1,left,right,l,m);
       auto rs=mini(2*i+2,left,right,m+1,r);
       if(ls.first<rs.first) return ls;
       else if(ls.first==rs.first) return {ls.first,ls.second+rs.second};

       return rs;   
    }
     pair<long long,long long> up(long long idx, long long val,long long i,long long l , long long h)
    {
       if(idx<l ||idx>h ) return seg[i];
        if(l==h) return seg[i]={val,1};
          long long m=(l+h)/2;
        
       auto ls=up(idx,val,2*i+1,l,m);
       auto rs=up(idx,val,2*i+2,m+1,h);
       if(ls.first<rs.first) return seg[i]=ls;
       else if(ls.first==rs.first) return  seg[i]={ls.first,ls.second+rs.second};
       return seg[i]=rs;  
    }
int main()
{
    
    f();
    
    long long n,q;
    cin>>n>>q;
    vector<long long>v(n);
    for(long long i=0;i<n;i++)
    {
        cin>>v[i];
    }
    seg.resize(4*n);
    build(0,n-1,0,v);
    while(q--)
    {
        long long t;
        cin>>t;
        if(t==1)
        {
            long long idx,val;
            cin>>idx>>val;
            up(idx,val,0,0,n-1);
        }
        else
        {
            long long l,r;
            cin>>l>>r;
            auto p=mini(0,l,r-1,0,n-1);
            cout<<p.first<<" "<<p.second<<endl;

        }
    }

    
    return 0;
}
  
