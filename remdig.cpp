#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1000001];

int n;
int rem(int val)
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
    int a=val;
    while(a>0)
    {   
        int b=a%10;
        if(b!=0)
       mn=min(mn,rem(val-b) );
        a=a/10;
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
    
   
    cin>>n;
   

    for (int i = 0; i <= 1000000; ++i)
    {
        /* code */
        dp[i]=-1;
    }
    int ans=rem(n);
    
    
    cout<<ans;

    return 0;
}