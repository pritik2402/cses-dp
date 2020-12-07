#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dp[101][100001];
bool b[100001];
int a[100];
int n;
void moneysum(int ind,int val)
{
  b[val]=true;
  if(ind==n)
    return;
  if(dp[ind][val])
    return;
  dp[ind][val]=true;
  
  moneysum(ind+1,val);
  moneysum(ind+1,val+a[ind]);
  return;

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
  
  cin>>n;
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];

  }
  for (int i = 0; i < n+1; ++i)
  {
    for (int j = 0; j < 100001; ++j)
    {
      dp[i][j]=false;
      
    }
  }
  for (int i = 0; i < 100001; ++i)
  {
    b[i]=false;
  }
  moneysum(0,0);
  int count=0;
  for (int i = 1; i < 100001; ++i)
  {
    if(b[i]==true)
      count++;
  }
  cout<<count<<endl;
  for (int i = 1; i < 100001; ++i)
  {
    if(b[i])
      cout<<i<<" ";
  }

    return 0;
}