
#include<bits/stdc++.h>
 
using namespace std;
 
#define MAX 922337203685477580
#define MIN -92233720368547750
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin>>n;
 
    vll a(n,0),b(n),c(n);
    map<ll,ll>mp;
 
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i]; 
        mp[a[i]]=1,mp[b[i]]=1;   
    }
 
 
    ll x = 0;
    for(auto&i:mp){
        i.second = ++x;
    }
    
    vector<vector<pair<ll,ll>>>sc(x+1);
 
    for(ll i=0;i<n;i++){
        sc[mp[b[i]]].push_back({mp[a[i]],c[i]});
    }
 
    vll dp(x+1,0);
 
    for(ll i=1;i<=x;i++){
        dp[i]=dp[i-1];
        for(auto j:sc[i]){
            dp[i] = max(dp[i],dp[j.first-1]+j.second);
        }
    }
    cout<<dp[x]<<'\n';
     
}