#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000][1000];
char a[1001][1001];
int n;
int m=1000000007;
ll path(int i,int j)
{

    if(i>=n||j>=n||a[i][j]=='*')
        return 0;
    
    if(i==n-1&&j==n-1)
     {  
        
        return 1;
     }
    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j]=(path(i+1,j)%m+path(i,j+1)%m)%m;
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // memset(dp,false,sizeof(dp));
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    
   
    cin>>n;
   
   for (int i = 0; i < n; ++i)
   {
       /* code */
    for (int j = 0; j < n; ++j)
    {
        dp[i][j]=-1;
        cin>>a[i][j];
    }
   }

   ll ans = path(0,0);
    
    cout<<ans;

    return 0;
}