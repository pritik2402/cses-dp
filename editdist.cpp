#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
   int n,m;
      string s1,s2;
      cin>>s1>>s2;
      n=s1.size();
      m=s2.size();
      int dp[n+1][m+1];
      
      for(int i=0;i<=n;i++)
      {
          
          for(int j=0;j<=m;j++)
          {
              if(i==0)
              dp[i][j]=j;
              else if(j==0)
              dp[i][j]=i;
              else if(s1[i-1]==s2[j-1])
              {
                  
                 
                  dp[i][j]=dp[i-1][j-1];
                 
                  
              }
              else
              {
                
                  dp[i][j]=1+min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
              }
              
          }
          
      }
      int ans=dp[n][m];
      cout<<ans<<"\n";

    return 0;
}