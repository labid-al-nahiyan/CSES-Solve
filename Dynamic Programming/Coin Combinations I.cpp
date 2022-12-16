#include<bits/stdc++.h>
 
using namespace std;
 
 
#define MAX 1e18
#define MIN -1e18
 
typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;
 
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
 
 
 
vll dp(1100100,0),a;
ll n,m,cnt=0;
 
void solve(ll x)
{
    if(x>m)return;
 
    if(x==m){
        cnt++;
        return;
    }   
 
    for( ll i = 0 ; i<a.size() ; i++ ){
         solve( x + a[i] );
    }
 
    return;
}
 
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
            if(i+j>m)continue;
            dp[i+j]=(dp[i+j]+dp[i])%1000000007;
        }
    }
 
   
     cout<<dp[m]%1000000007;
}