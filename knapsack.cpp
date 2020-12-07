#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1001][100001];
int page[1000],price[1000];
int n;
int book(int ind,int val)
{
   // cout<<ind<<" "<<val<<" ";

    if(val<0)
        return -100000;
    if(val==0||ind==n)
        return 0;
    if(dp[ind][val]!=-1)
        return dp[ind][val];
    
    if(val-price[ind]>=0)
        dp[ind][val]=max(book(ind+1,val),page[ind]+book(ind+1,val-price[ind] ));
    else
        dp[ind][val]=book(ind+1,val);


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
    
   int x;
    cin>>n>>x;
   
    for (int i = 0; i < n; ++i)
    {
        cin>>price[i];

    }
    for (int i = 0; i < n; ++i)
    {
        cin>>page[i];
    }
   
   memset(dp,-1,sizeof(dp));
   int ans = book(0,x);
    
    cout<<ans;

    return 0;
}