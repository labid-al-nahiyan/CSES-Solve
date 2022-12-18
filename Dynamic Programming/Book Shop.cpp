// 0/1-Knapsack problem 

#include<bits/stdc++.h>

using namespace std;


#define MAX 992337203685477580
#define MIN -99233720368547750

typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;

vector<ll> K[100050];

int knapSack(ll W, vll wt, vll val, ll n)
{
    
    ll dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (ll i = 1; i <= n ; i++) {
        for (ll w = W; w >= 0; w--) {
 
            if (wt[i - 1] <= w)
               
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; 
}

ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int main(){
    ll n,w;
    cin>>n>>w;

    vll wt(n+1),val(n+1);

    for (int i = 0; i < n; ++i)
    {
        cin>>wt[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>val[i];
    }
    
    ll ans = knapSack(w,wt,val, n);
    cout<<ans<<'\n';



}