
int Solution::solve(vector<int> &A) {
    int n=A.size();
    
    vector<int>v(n);
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        maxi=max(A[i],maxi);
        v[i]=maxi;
    }
    set<int>st;
    st.insert(A[0]);
    int ans=INT_MIN;
    for(int i = 1; i < n - 1; i++)
    {
         st.insert(A[i]);
        auto it=st.find(A[i]);
        if(it!=st.begin() && A[i]!=v[i])
        ans=max(ans,*(--it)+v[i]+A[i]);

    }

    return ans;
    
}
