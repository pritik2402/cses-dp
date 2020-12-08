#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool sortbysec(const tuple<ll, ll, ll>& a,  
               const tuple<ll, ll, ll>& b) 
{ 
    return (get<1>(a) < get<1>(b)); 
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
  int n;
  cin>>n;
 std::vector<tuple<ll,ll,ll> > v;
 for (int i = 0; i < n; ++i)
 {
   ll x,y,z;
   cin>>x>>y>>z;
   v.push_back( make_tuple(x, y, z));

 }
 sort(v.begin(),v.end(),sortbysec);
 ll end[n+1];
 end[0]=0;
 for (int i = 0; i < n; ++i)
 {
  end[i+1]=get<1>(v[i]);
 }
 ll a[n+1];
 a[0]=0;
 for (int i = 1; i < n+1; ++i)
 {
    int b=lower_bound(end,end+n+1,get<0>(v[i-1]))-end;
   a[i]=max(a[b-1]+get<2>(v[i-1]),a[i-1]);
 }
 cout<<a[n];


    return 0;
}