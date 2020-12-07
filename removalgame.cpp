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
  int n;
  cin>>n;

  ll a[n+1];
  a[0]=0;
  for (int i = 1; i <= n; ++i)
  {
    cin>>a[i];
  }
  ll sum[n+1];
  sum[0]=0;
  for (int i = 0; i < n; ++i)
  {
    sum[i+1]=sum[i]+a[i+1];
  }

  ll dp[n+1][n+1];
  int i=0,j=0;
  for(j=0;j<n;j++)
  {

    for(i=1;i+j<=n;++i)
    {
      if(j==0)
        dp[i][i+j]=a[i];
      else if (j==1)
      {
        dp[i][i+j]=max(a[i],a[i+j]);
      }
      else
      {
        dp[i][i+j]=max( a[i]+ (sum[i+j]-sum[i]-dp[i+1][i+j]) , a[i+j] + ( sum[i+j-1]-sum[i-1] - dp[i][i+j-1])  );
      }
    }

  }
  cout<<dp[1][n];

    return 0;
}