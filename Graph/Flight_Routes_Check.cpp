#include<bits/stdc++.h>

using namespace std;


vector<int> adj[100050], adj_rev[100050];
vector<bool> used(100050,0);
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v]){
        if (!used[u]){
            dfs1(u);
        }
    }

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj_rev[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        if (!used[i]){
            dfs1(i);
        }
    }

    used.assign(n, false);

    reverse(order.begin(), order.end());

    vector<int>com;
    for (auto v : order){
        if (!used[v]) {
            dfs2 (v);
            component.clear();
            com.push_back(v);
        }

    }

    if(com.size()>1){
        cout<<"NO"<<'\n';
        cout<<com[1]+1<<" "<<com[0]+1<<'\n';
    }
    else{
        cout<<"YES\n";
    }
}

