#include<bits/stdc++.h>
 
using namespace std;
 
 
#define MAX 992337203685477580
#define MIN -99233720368547750
 
typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;
 
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
 
int main(){
   
    
        string s1,s2;
        cin>>s1>>s2;
        ll n = s1.size(),m = s2.size();
 
        ll dp[m+5][n+5];
 
 
 
        for(ll i=0;i<=m;i++){
            for(ll j=0;j<=n;j++){
                if(i==0){
                    dp[i][j] = j;
                }
                else if(j==0){
                    dp[i][j] = i;
                }
 
                else if(s2[i-1]==s1[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }    
                cout<<dp[m][n];
                
 
    
}