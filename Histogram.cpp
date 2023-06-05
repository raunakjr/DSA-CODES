int Solution::largestRectangleArea(vector<int> &A) {
    int n=A.size();
    vector<int>v;
    v.clear();
    vector<int>L(n,-1);
    for(int i=0;i<n;i++)
    {
        while(v.size()>0 && A[v.back()]>=A[i])
        {
            v.pop_back();
        }
        if(v.size()>0) L[i]=v.back();
        else L[i]=-1;
        v.push_back(i);
    }
    v.clear();
    vector<int>R(n,n);
    for(int i=n-1;i>=0;i--)
    {
        while(v.size()>0 && A[v.back()]>=A[i])
        {
            v.pop_back();
        }
        if(v.size()>0) R[i]=v.back();
        v.push_back(i);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
  
      ans=max(ans,A[i]*(abs(L[i]-R[i])-1)) ; 
    }
    return ans;
}
