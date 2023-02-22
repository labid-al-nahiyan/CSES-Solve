#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int > vi;
typedef vector<long long> vll;

const long long int MAX = 100000000000000000;
const long long int MIN = -10000000000000000;

vector<pair<ll, ll>> adj[100050];
ll d[100050][11];
int n,m,k;

void dijkstra(int s) { 
   
    d[s][0] = 0;

    using pii = pair<ll, ll>;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});

    while (!q.empty()) {

        ll v = q.top().second;
        ll d_v = q.top().first;
        
        q.pop();

         if (d_v > d[v][k-1])
             continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d_v + len < d[to][k-1]) {

                d[to][k-1] = d_v + len;   
                sort(d[to],d[to]+k); 
                q.push({d_v+len, to});

           }
        }
        
    }

    for(int i=0;i<k;i++){
        cout<<d[n][i]<<" ";
    }
    cout<<'\n';

}



int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin>>n>>m>>k;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            d[i][j] = MAX;
        }
    }

    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        
        adj[x].push_back({y,z});
    }

    dijkstra(1);

}