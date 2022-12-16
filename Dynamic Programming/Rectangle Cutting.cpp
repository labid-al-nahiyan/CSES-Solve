#include<bits/stdc++.h>
 
using namespace std;
 
 
#define MAX 922337203685477580
#define MIN -92233720368547750
 
typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;
 
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
 
ll dp[510][510];
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n,m;
    cin>>n>>m;
 
    for(ll i=2;i<=n;i++)dp[i][1]=i-1;
    for(ll i=2;i<=m;i++)dp[1][i]=i-1;
    dp[1][1]=0;
 
    for(ll i=2;i<=n;i++){
        for(ll j=2;j<=m;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            ll x = MAX;
            for(ll k=1;k<=j/2;k++){
                x = min(x, dp[i][k]+dp[i][j-k]);
            }
            ll y = MAX;
            for(ll k = 1;k<=i/2;k++){
                y = min(y, dp[k][j]+dp[i-k][j]);
            }
            dp[i][j]=min(x,y)+1;
        }
    }
    cout<<dp[n][m]<<'\n';
    
}