#include<bits/stdc++.h>
 
using namespace std;
 
 
#define MAX 992337203685477580
#define MIN -99233720368547750
#define MOD 1000000007
 
typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;
 
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
 
string grid[1010];
ll dp[1010][1010];
 
ll ans = 0;
 
 
 
int main(){
    int n;
    cin>>n;
    string s;
 
 
    for(ll i=0;i<n;i++){
        cin>>grid[i];
    }
    dp[0][0] = 1;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(grid[i][j]=='*')continue;
            if(grid[i+1][j]=='.'){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=MOD;
            }
            if(grid[i][j+1]=='.'){
                dp[i][j+1]+=dp[i][j];
                dp[i][j+1]%=MOD;
            }
        }   
    }
    
    if(grid[n-1][n-1]=='*')cout<<0<<'\n';
    else cout<<(dp[n-1][n-1]%MOD)<<'\n';
 
}