#include<bits/stdc++.h>

//using namespace std;

#define MAX 992337203685477580
#define MIN -99233720368547750
#define MOD 1000000007
typedef long long ll;
typedef std::vector<int > vi;
typedef std::vector<long long> vll;

std::vector<int> adj[100050];
int n; 
std::vector<int> visited(100050,0);

vll cnt(100050,0);

void dfs(int v) {
    visited[v] = 1;

    for (int u : adj[v]){

        if(u==n)cnt[v]++;

        else if (visited[u] == 0){

            dfs(u);
           
        }
        cnt[v]+=cnt[u];
        cnt[v]%=MOD;

    }

    visited[v] = 2;
}


int main(){

    
    int m;
    std::cin>>n>>m;


    for(int i=0;i<m;i++){
        int x,y;
        std::cin>>x>>y;
        adj[x].push_back(y);
    }

    dfs(1); 

    std::cout<<cnt[1]%MOD<<'\n';

}