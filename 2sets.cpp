#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[501][70000];
int a[501];
int m=1000000007,mod=1000000007;

int n;
long long int expo(long long int base,long long int power)
{
    if(power==0)return 1;
    if(power==1)return base;
    if(power%2==0)
    {
        long long int res= expo(base,power/2);
        res= ((res%mod)* (res%mod))%mod;
        return res;
    }
    else
    {
        long long int res= expo(base,power/2);
        res= ((res%mod) * (res%mod))%mod;
        res= ((res%mod) * (base%mod))%mod;
        return res;
    }

}
ll sets(int ind,int val)
{
  
  if( val==(n*(n+1)/4) )
{
  return 1;
}
  
  if(  ind==n || val> (n*(n+1)) /4   ) 
    return 0;
  if(dp[ind][val]!=-1)
    return dp[ind][val];
  dp[ind][val]=(sets(ind+1,val)%m+sets(ind+1,val+a[ind])%m)%m;
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
  
  cin>>n;
  
  for (int i = 0; i < n+1; ++i)
  {
    for (int j = 0; j < ( (n*(n+1) )/4)+2; ++j)
    {
      dp[i][j]=-1;
      
    }
  }
 for (int i = 0; i < n; ++i)
 {
   a[i]=i+1;
 }
  
  if(( n*(n+1) )%4!=0 )
  { 
    cout<<"0";
    return 0;
  }
  ll ans=sets(0,0);
  ans=((ans %m)* (expo(2, m-2)%m))%m;
  cout<<ans;


    return 0;
}