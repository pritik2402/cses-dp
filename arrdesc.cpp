#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100001][101];
ll a[100000];
ll n,m,mod=1000000007;
ll ans=1;

ll arr(int ind,ll val)
{
    //cout<<ind<<val;
    if(ind==n)
        return 1;
    if(val>m)
        return 0;
    if(a[ind]!=0)
    {
       // cout<<ind<<" "<<val<<" "<<endl;
        if(abs(val-a[ind]) ==1||val==a[ind] )
            return 1;
        else
            return 0;
    }
    
    
    if(dp[ind][val]!=-1)
        return dp[ind][val];

    if(val==m)
        dp[ind][val]= (arr(ind+1,val)%mod+arr(ind+1,val-1)%mod)%mod;
    else if(val==1)
        dp[ind][val]=(arr(ind+1,val)%mod+arr(ind+1,val+1)%mod)%mod;
    else 
        dp[ind][val]=((arr(ind+1,val)%mod+arr(ind+1,val+1)%mod)%mod+arr(ind+1,val-1)%mod)%mod;

   
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
    
   cin>>n>>m;

   for (int i = 0; i < n; ++i)
   {
       cin>>a[i];
   }
   for (int i = 0; i < n+1; ++i) 
   {
       for (int j= 0; j < m+1; ++j)
       {
            dp[i][j]=-1;
       }
   }

   if(m==1)
   {
    cout<<ans;
    return 0;
   }

   for (int i = 0; i < n; ++i)
   {

        if(a[i]!=0&&i!=n-1&&a[i+1]!=0)
        {
          if(abs(a[i+1]-a[i])>1)
            
            {
              cout<<"0";
              return 0;
            }

        }
        if(i==0&&a[i]==0)
        {   
            ans=0;
            for (int j = 1; j < m+1; ++j)
            {
                    ans=(ans%mod+arr(i+1,j)%mod)%mod;                
            }
        }
        if(a[i]!=0&&i!=n-1&&a[i+1]==0)
        {
            
            ans=(ans%mod*arr(i+1,a[i])%mod)%mod;

        }


        
   }
  // cout<<dp[1][2]<<" "<<dp[2][3]<<dp[2][2]<<dp[2][1]<<endl;
   cout<<ans;
    

    return 0;
}