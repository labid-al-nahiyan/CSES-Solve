#include<bits/stdc++.h>
 
using namespace std;
 
 
#define MAX 1e18
#define MIN -1e18
 
typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;
 
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
 
 
 
vll dp(1000100,MAX), a ;
ll n,m;
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin>>n>>m;
    dp[0]=0;
    for(ll i=0;i<n;i++){
        ll x; 
        cin>>x;
        a.push_back(x);
        dp[x]=1;
    }
    for(ll i=0;i<=m;i++){
        for(auto j:a){
            if(j<=i) dp[i] = min(dp[i],dp[i-j]+1);
        }
    }
    if(dp[m]==MAX)cout<<-1<<'\n';
    else cout<<dp[m]<<'\n';
}