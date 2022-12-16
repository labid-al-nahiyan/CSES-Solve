#include<bits/stdc++.h>
 
using namespace std;
 
 
#define MAX 1e18
#define MIN -1e18
#define MOD 1000000007
 
 
typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;
 
 
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
 
 
ll dp[1000100];
vll a;
ll n,m,cnt=0;
 
 
int main()
{
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        ll x; 
        cin>>x;
        a.push_back(x); 
 
    }
    dp[0]=1;
 
    sort(a.begin(),a.end());
 
    for(ll i=0;i<n;i++){
        for(ll j=1;j<=m;j++){ 
            if(j-a[i]<0)continue;                          
            dp[j]  =  (dp[j]+dp[j-a[i]])%MOD;
        }
    }
 
    cout<<dp[m]%MOD<<'\n';
    
 
 
}