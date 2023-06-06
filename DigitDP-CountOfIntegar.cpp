class Solution {
public:
    // n=22 
    long dp[25][225][2];
    int mod=1e9+7;
    int f(string &s, int pos, int sum, int tight, int mini, int maxi)
    {
        if(pos==s.size())
        {
            return sum>=mini and sum<=maxi;
        }
        if(dp[pos][sum][tight]!=-1) return dp[pos][sum][tight]%mod;
        if(tight==1)
        {
            long res=0;
            for(int i=0;i<=s[pos]-'0';i++)
            {
                if(i==s[pos]-'0') res+=f(s,pos+1,sum+i,1,mini,maxi);
                else res+=f(s,pos+1,sum+i,0,mini,maxi);
                res=res%mod;
            }
         
            return dp[pos][sum][tight]=res;
        
        }
        long res=0;
        for(int i=0;i<=9;i++)
        {
            res+=f(s,pos+1,sum+i,0,mini,maxi);
            res=res%mod;
        }
       
        return dp[pos][sum][tight]=res;

    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        int ans1=f(num2,0,0,1,min_sum,max_sum);
        memset(dp,-1,sizeof(dp));
       
        int ans2=f(num1,0,0,1,min_sum,max_sum);
        int sum = 0;
        for (auto i : num1)
            sum += (i - '0');

        if (sum >= min_sum and sum <= max_sum)
            ans2--;
        return ((ans1-ans2)+mod)%mod;

    }
};
