#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100];
int n,x;
ll dp[100][1000000];
int m=1000000007;
ll coin(int ind,ll val)
{
  if(val==0)
    return 1;
  if(ind==n||val<0)
    return 0;
  if(dp[ind][val]!=-1)
    return dp[ind][val];
  dp[ind][val]=(coin(ind,val-a[ind])%m+coin(ind+1,val)%m)%m;
  return dp[ind][val];
}

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
    
    cin>>n>>x;
    for (int i = 0; i < n; ++i)
    {
      cin>>a[i];
    }
    for (int i = 0; i < n+1; ++i)
    {
      for (int j = 0; j < x+1; ++j)
      {
        dp[i][j]=-1;
      }
    }
    ll ans=coin(0,x);
    cout<<ans;
    
    return 0;
}
