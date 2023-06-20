class Solution {
public:
     int mod=1e9+7;
    int maxPerformance(int n, vector<int>& nums1, vector<int>&nums2, int k) {
         using ll = long long;
        using pll = pair<ll, ll>;
       // int n = nums1.size();
        vector<pll> arr;
        for(int i=0; i<n; i++) {
            arr.push_back({nums2[i], nums1[i]});
        }
        sort(arr.begin(), arr.end(), greater<pll>());
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll sum=0;
       
        ll ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(pq.size()==k)
            {
                sum=sum-pq.top();
                pq.pop();
            }
             sum=sum+arr[i].second;
             pq.push(arr[i].second);
            ans=max(ans,sum*arr[i].first);
           
        }
        return ans%mod;
        
    }
};
