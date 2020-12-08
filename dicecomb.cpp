#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m=1000000007;
    cin>>n;
    if(n<7)
    {
        cout<<(1<<(n-1));
        return 0;
    }
    int a[n+1];
    a[0]=0;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    a[4]=8;
    a[5]=16;
    a[6]=32;
    
    for(int i=7;i<=n;i++)
        a[i]=(((((a[i-1]%m+a[i-2]%m)%m+a[i-3]%m)%m+a[i-4]%m)%m+a[i-5]%m)%m+a[i-6]%m)%m;
    
    cout<<a[n];
    return 0;
}