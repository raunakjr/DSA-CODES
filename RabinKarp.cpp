vector <int> search(string pat, string s)
        {
            //code here.
        vector<int>v;
        int k=pat.size();
        int n = s.length();
        long mod =1e9+7; 
        long pow = 31;
        
        vector<long> p(k,1);
        for(int i=1;i<k;i++)  p[i] = ( p[i-1] * pow ) % mod; 
        
        long pHash = 0;
        for (int i = 0; i <k; i++)pHash = (pHash + (pat[i]-'a'+1) * p[i]) % mod;
        
        vector<long> vs(n);
        for(int i=0;i<n;i++) vs[i] = (s[i]-'a'+1) % mod;
        
        long H = 0;
        for(int i=0;i<k;i++) 
        {
            int pos = i + n-k;
            long item = (vs[pos]*p[i]) % mod; 
            H = (H + item) % mod;
        }
        if ( H == pHash ) v.push_back(n-k+1);
		
        for(int i = (n-k) -1; i >= 0; i--) 
        {
            long removed_factor = vs[k+i]*p[k-1] % mod;
            
            long added_factor = vs[i];
            
            H = (mod + H - removed_factor) % mod;
            H = (pow * H) % mod;
            H = (H + added_factor) % mod;
            if (H == pHash  ) v.push_back(i+1);
        } 
        
        reverse(v.begin(),v.end());
        if(v.size()==0) return {-1};
        return v;
        }
