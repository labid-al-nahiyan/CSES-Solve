#include<bits/stdc++.h>

using namespace std;


#define MAX 992337203685477580
#define MIN -99233720368547750

typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;

ll dp[5001][5001],a[5001];


ll solve(ll i , ll j , ll player){

	if(dp[i][j]!=0){
		if(player)return 0;
		else return dp[i][j];
	}

	if(i==j){
		if(player)return 0;
		else return a[j];
	}

	if(player==1){
			return min(solve(i+1,j,(player+1)%2) , solve(i,j-1,(player+1)%2));
	}

	return dp[i][j] = max(a[i]+solve(i+1,j,(player+1)%2),a[j]+solve(i,j-1,(player+1)%2));

}

int main(){
	ll n;
	cin>>n;

	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans = solve(0,n-1,0);
	cout<<ans<<'\n';

	
}