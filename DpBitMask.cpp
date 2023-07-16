class Solution {
public:
    vector<int>res;
     unordered_map<string , int > dp;
    void f(int idx,vector<int>&arr,int t, int bit,vector<int>&temp)
    {

                if(bit==t)
                {
                    if(res.size()==0 || res.size()>temp.size()) res=temp;
                    return ;
                }
                
               if(idx>=arr.size())
               {
                   return ;
                
               }
               string s = to_string(idx) + to_string(bit);
        
                if(dp[s]!=-1 && dp[s]!=0)
                {
                if(dp[s] <= temp.size()) // already small size res present
                return ; 
                }
        


              f(idx+1,arr,t,bit,temp);
              if((bit | arr[idx])!=bit)
              { 
              temp.push_back(idx);
              f(idx+1,arr,t,bit| arr[idx], temp);
              temp.pop_back();
              dp[s] = (temp.size() != 0 ) ? temp.size() : -1;
              }



    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        vector<int>arr;
        unordered_map<string,int>mp;
        int i=0;
        for(auto s:req_skills) mp[s]=i++;
        
        for(auto v:people)
        {
            int bit=0;
            for(auto s:v)
            {
                bit=bit | (1<<mp[s]);
            }
            arr.push_back(bit);
        }
         int n=req_skills.size();
         int t=pow(2,n)-1;
         vector<int>temp;
         f(0,arr,t,0,temp);
         return res;

    }
};
