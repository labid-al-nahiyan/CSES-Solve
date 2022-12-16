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


ll dp[100010][110];

int main(){
    
    ll n,m;
    cin>>n>>m;

    vll a(n,0);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    if(a[0]==0){
        for(ll i=0;i<=m;i++){
            dp[0][i] = 1;
        }
    }
    else{
        dp[0][a[0]] = 1;
    }

    for(ll i=1;i<n;i++){

        if(a[i]==0){
            for(ll j=1;j<=m;j++){
                dp[i][j] = dp[i-1][j];
                dp[i][j]%=MOD;

                if(j+1<=m){
                    dp[i][j]+=dp[i-1][j+1];
                    dp[i][j]%=MOD;
                }
                if(j-1>=1){
                    dp[i][j]+=dp[i-1][j-1];
                    dp[i][j]%=MOD;
                }
            }
        }
        else{
            dp[i][a[i]] = dp[i-1][a[i]];
            dp[i][a[i]]%=MOD;

            if(a[i]+1<=m){
                dp[i][a[i]]+=dp[i-1][a[i]+1];
                dp[i][a[i]]%=MOD;
            }
            if(a[i]-1>=1){
                dp[i][a[i]]+=dp[i-1][a[i]-1];
                dp[i][a[i]]%=MOD;
            }
            
        }
        
    }
    // for(ll i=0;i<n;i++){
    //     for(ll j=1;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }

    ll ans  = 0;

    if(a[n-1]==0){
        for(ll i=1;i<=m;i++){
            
            ans+=dp[n-1][i];
            ans%=MOD;
        }
    }
    else{
        ans = dp[n-1][a[n-1]];
        ans%=MOD;
    }
    cout<<ans<<'\n';


}