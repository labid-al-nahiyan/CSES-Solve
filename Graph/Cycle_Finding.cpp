#include<bits/stdc++.h>

using namespace std;



typedef long long int ll;
typedef vector<int > vi;
typedef vector<long long> vll;

long long int MAX = 9923372036854775;
long long int MIN = -99233720368547750;

ll n, m, v=0;

vector<int> adj[2550];
ll grid[2550][2550];

map<pair<int,int>,int>mp;

vector<ll> d (2550);
vector<int> p (2550, - 1);

vector<pair<int,int>> e;


void solve()
{
    d[0] = 0;p[0] = 0;
    int x;
     for (int i=0; i<n; ++i)
     {
        x = -1;
        for (auto j:e){

           //  if (d[j.first] < MAX){
                if (d[j.second] > d[j.first] + grid[j.first][j.second])
                {
                    
                    ll y = d[j.first] + grid[j.first][j.second];
                   
                    d[j.second] = max (MIN,y);
                    p[j.second] = j.first;
                    x = j.second;
                 }
          //  }
         }
         
    }

    if (x==-1){
        cout<<"NO\n";
    }
    
    else
    {
         cout<<"YES\n";
         for (int i=0; i<n; ++i)
             x = p[x];

         vector<int> path;
        
         int cur = x ;
         for (cur=x;;cur=p[cur])
         {
             path.push_back (cur);
             if(cur==x && path.size()>1)break;
         }
        
         reverse(path.begin(),path.end());
         for(size_t i=0;i<path.size();i++){
             cout<<path[i]+1<<" ";
         }
        
       
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        d[i] = MAX;
        for(int j=0;j<=n;j++){
            grid[i][j] = MAX;
        }
    }

    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        
        if(mp[{x-1,y-1}]==0){
            e.push_back({x-1,y-1});
            adj[x-1].push_back(y-1);
            mp[{x-1,y-1}] = 1;
        }

        grid[x-1][y-1] = min(grid[x-1][y-1], (ll)z);
    }

    solve();

}