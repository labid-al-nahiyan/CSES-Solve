#include<bits/stdc++.h>
 
using namespace std;
 
#define MAX 992337203685477580
#define MIN -99233720368547750
#define MOD 1000000007
typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;
 
 
int n,m;
vector<pair<ll, int>> adj[100050];
vll d(100050,MIN);
vi p(100050,-1);
 
void dijkstra(int s) {
    
    d[s] = 0;
    using pii = pair<ll, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
 
        int v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
 
        if (d_v != d[v])
            continue;
 

        for (auto u : adj[v]) {
            ll len = u.first;
            int to = u.second;
            if (d[v] + 1 > d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
    
    vector<int> path;
    int y = n;
 
    for (int cur=y; cur!=-1 ; cur=p[cur])
    {
        path.push_back (cur);
       
    }
 
    reverse (path.begin(), path.end());
 
    if(p[n]==-1){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout << path.size()<<"\n";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin>>n>>m;
 
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
 
        adj[x].push_back({1,y});

    }
 
    dijkstra(1);
 
}