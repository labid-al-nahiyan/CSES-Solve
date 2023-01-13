#include<bits/stdc++.h>

using namespace std;


#define INF 2147483647
typedef long long int ll;
typedef vector<int > vi;
typedef vector<long long> vll;

long long int MAX = 9923372036854775;
long long int MIN =  -99233720368547750;

struct edge
{
    int a, b;
};

ll n, m, v=0;
vector<edge> e;
int s;

vector<int> adj[2550];
ll grid[2550][2550];

vector<int> used(2550,0),dis(2550), par(2550,-1);
vector<long long int> d (2550, MAX);
vector<int> p (2550, - 1),cyc(2550,0);


int super_bfs(int sr,int mid,int des){
    for(int i=0;i<=n;i++){
        used[i] = 0;
        dis[i] = 0;
        par[i]  =-1;
    }


    s=sr;
    int chk = 0;
    queue<int> q;
    q.push(s);
    used[s] = 1;
    par[s] = -1, dis[s] = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = 1;
                q.push(u);
                dis[u] = dis[v] + 1;
                par[u] = v;
                
                if(u==mid){
                   chk = 1;
                }
            }
            if(chk)break;
        }
        if(chk)break;
    }
    
    for(int i=0;i<=n;i++){
        used[i] = 0;
        dis[i] = 0;
        par[i]  =-1;
    }
    while(!q.empty())q.pop();

    s=mid;
    q.push(s);
    used[s] = 1;
    par[s] = -1, dis[s] = 0;;
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int u : adj[v]) {

            if (!used[u]) {
                used[u] = 1;
                q.push(u);
                dis[u] = dis[v] + 1;
                par[u] = v;
                
                if(u==des){
                    return 1;
                }
            }
        }
    } 

    return 0;
    
}

int negCyc(int x){
    int y = x,check = 0;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        
        int cur = x ;
        for (cur=x;;cur=p[cur])
        {
            path.push_back (cur);
            cyc[cur]=0;
            if(cur==x && path.size()>1)break;
        }
        
        
        for(size_t i=0;i<path.size();i++){
            if(super_bfs(0,path[i],n-1)){
                check = 1;
            }
        }
        
       if(check)return 1;
       else{
            return 0;
        }
}


void solve()
{
    d[0] = 0;p[0] = 0;
    int x;
     for (int i=0; i<n; ++i)
     {
        x = -1;
        for(int j=0;j<n;j++)cyc[j]=0;
        for (size_t j=0; j<e.size(); ++j){

             if (d[e[j].a] < MAX){
                if (d[e[j].b] > d[e[j].a] + grid[e[j].a][e[j].b])
                {
                    
                    long long int y = d[e[j].a] + grid[e[j].a][e[j].b];
                   
                    d[e[j].b] = max (MIN,y);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                    cyc[x] = 1;
                 }
            }
         }
         
    }
    if (x==-1){
        cout<<d[n-1]*(-1ll)<<'\n';
    }
    else if(cyc[n-1]!=0){
        cout<<"-1"<<"\n";
    }
    else
    {
        
        for(int i=0;i<n;i++){
            if(cyc[i]==1){
               cyc[i] = 0;
               if(negCyc(i)){
                    cout<<"-1";
                    return;
               }
               
            }
        }
        cout<<d[n-1]*(-1)<<'\n';
        return;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            grid[i][j] = MAX;
        }
    }

    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edge ed;
        ed.a = x-1;ed.b = y-1;
        
        adj[x-1].push_back(y-1);

        if(grid[x-1][y-1]==MAX)e.push_back(ed);

        grid[x-1][y-1] = min(grid[x-1][y-1], (-1ll)*z);
    }

    solve();

}