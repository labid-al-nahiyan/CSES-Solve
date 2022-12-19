#include<bits/stdc++.h>

using namespace std;


#define MAX 992337203685477580
#define MIN -99233720368547750

typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;

ll dp[100050];


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,sum=0;
    cin>>n;
    vll a(n,0);

    for(ll i=0;i<n;i++){
         
        cin>>a[i]; 
        sum+=a[i];
       
 
    }
    
 	

    sort(a.begin(),a.end());
    vll pre(n,0);

    for(ll i=0;i<n;i++){
    	if(i==0){
    		pre[i] = a[i];
    	}
    	else{
    		pre[i]+=pre[i-1]+a[i];
    	}
    }
 
    for(ll i=0;i<n;i++){
    	vll c;
        for(ll j=1;j<=sum;j++){ 
            if(j-a[i]<=0)continue;        
            if(j>pre[i])break;

            if(dp[j]==0){

            	ll x = dp[j-a[i]];
            	if(x) c.push_back(j);
            }
        }
        for(auto i:c){
        	dp[i] = 1;
        }
        
        dp[a[i]] =  1;

    }
 
    
    ll ans = 0;
    vll b;

    for(ll i=1;i<=sum;i++){
    	if(dp[i]!=0){
    		b.push_back(i);
    	}
    }

    cout<<b.size()<<'\n';
    for(ll i=0;i<b.size();i++){
    	cout<<b[i]<<" ";
    }

 


}