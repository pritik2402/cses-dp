#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m=1000000007;
int n;
int dp[1000001];
int ways(int val,int c[])
{
    if(val <0)
        return 0;
    if(val==0)
        return 1;
    if(dp[val]!=-1)
        return dp[val];
    int sum=0;
    for (int i = 0; i < n; ++i)
    {

        sum=(sum%m+ways(val-c[i],c)%m)%m;
    }
    dp[val]=sum;
 return dp[val];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //memset(dp,false,sizeof(dp));
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
    for (int i = 0; i < x+1; ++i)
    {
        /* code */
        dp[i]=-1;
    }
    int ans=ways(x,c);
    cout<<ans;

    return 0;
}