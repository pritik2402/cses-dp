#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1000001];

int n;
int coin(int val,int c[])
{

    if(val<0)
        return 10000000;
    
    if(val==0)
    {
             return 0;
    }
    if(dp[val]!=-1)
        return dp[val];
    int mn=10000001;
    for (int i = 0; i < n; ++i)
    {
       mn=min(mn,coin(val-c[i],c) );
    }
    dp[val]=1+mn;
    return dp[val];
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
    
    int x;
    cin>>n>>x;
    int c[n];
    for (int i = 0; i < n; ++i)
    {
        /* code */
        cin>>c[i];
    }

    for (int i = 0; i <= 1000000; ++i)
    {
        /* code */
        dp[i]=-1;
    }
    int ans=coin(x,c);
    if(ans>=10000000)
        ans=-1;
    
    cout<<ans;

    return 0;
}