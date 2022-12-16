#include<bits/stdc++.h>
 
using namespace std;
 
#define MAX 922337203685477580
#define MIN -92233720368547750
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin>>n;
 
    vll a(n+1,0);
 
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    
 
    vll b;
    for(ll i=0;i<n;i++){
 
        auto it = lower_bound(b.begin(),b.end(),a[i]);
        if(it==b.end()) b.push_back(a[i]);
        else *it = a[i];
 
    }
    cout<<b.size()<<'\n';
}