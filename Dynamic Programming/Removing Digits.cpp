#include<bits/stdc++.h>

using namespace std;


#define MAX 992337203685477580
#define MIN -99233720368547750

typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;

ll dp[1000050];

ll solve(ll n){

	if(n<10)return 1;
	if(dp[n]!=0)return dp[n];

	ll r=n,ans = MAX;

	while(r!=0){
		ll q = r%10;
		r/=10;

		if(q!=0)ans=min(ans,solve(n-q)+1);
	}
	return dp[n]=ans;
}

int main(){

	ll n;
	cin>>n;

	ll ans = solve(n);

	cout<<ans<<'\n';

}