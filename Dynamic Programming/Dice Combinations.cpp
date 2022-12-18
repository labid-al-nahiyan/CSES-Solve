#include<bits/stdc++.h>

using namespace std;


#define MAX 992337203685477580
#define MIN -99233720368547750
#define MOD 1000000007

typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;


int mem[1000050];

int solve(int x,int n){

	if(x==0) return 1;
	if(mem[x]!=0)return mem[x];


	int ans = 0;

	
	for(int i=1;i<=6;i++){
		if(x-i>=0){
			ans += solve(x-i,n) ;
			ans %= MOD ;
		}


	}
	return mem[x] = ans%MOD;

}

int main(){

	int n;
	cin>>n;

	solve(n,n);

	cout<<mem[n];

}