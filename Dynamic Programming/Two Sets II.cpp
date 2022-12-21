#include<bits/stdc++.h>

using namespace std;


#define MAX 992337203685477580
#define MIN -99233720368547750
#define MOD 2000000014

typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;


ll dp[1000050];

int main(){
	ll n;
	cin>>n;


	ll sum = 0;

	sum = (n*(n+1))/2;


	if(sum%2){
		cout<<0<<'\n';
	}
	else{

		

		dp[0] = 1;

		sum/=2;


		for(ll i=1;i<=n;i++){

			for(ll j=sum ;j>=1;j--){

				if(j-i<0)break;

				dp[j] = (dp[j-i]+dp[j])%MOD;

			}

		}

		cout<<(dp[sum])/2<<'\n';


	}
}