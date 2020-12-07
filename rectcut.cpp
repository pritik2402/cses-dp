#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[501][501];


int rect(int a,int b)
{

  if(a==b)
    return 0;
  if(dp[a][b]!=-1)
    return dp[a][b];
  int mn=1000000;
  for (int i = 1; i < a; ++i)
  {
    mn=min(mn,rect(i,b)+rect(a-i,b));
  }
  for (int i = 1; i < b; ++i)
  {
    mn=min(mn,rect(a,i)+rect(a,b-i));
  }
  dp[a][b]=1+mn;
  return dp[a][b];


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
  for (int i = 0; i < 501; ++i)
  {
    for (int j = 0; j < 501; ++j)
    {
      dp[i][j]=-1;
    }
  }
  int a,b;
  cin>>a>>b;

  int ans=rect(a,b);
  cout<<ans;

    return 0;
}