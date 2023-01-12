#include<bits/stdc++.h>

using namespace std;

#define MAX 992337203685477580
#define MIN -99233720368547750
#define MOD 1000000007
typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;


vector<int> adj[1000500];
int n; // number of node
int s2=0,s1; // source vertex

queue<int> q;
vector<int> used(1000050,0),dis(1000050), dis1(1000050),par(1000050,-1);

void bfs(){
	q.push(s2);
	used[s2] = 1;
	dis[s2] = 0;
	while (!q.empty()) {
	    int v = q.front(); q.pop();
	    for (int u : adj[v]) {
	        if (!used[u]) {
	            used[u] = 1;
	            q.push(u);
	            dis[u] = dis[v] + 1;
	            
	        }
    }
}
}
void bfs1(){
	q.push(s1);
	used[s1] = 1;
	dis1[s1] = 1;
	par[s1] = -1;
	while (!q.empty()) {
	    int v = q.front(); q.pop();
	    for (int u : adj[v]) {
	        if (!used[u]) {
	            used[u] = 1;
	            
	            if(dis1[v]+1<dis[u] || dis[u]==0){

	            	q.push(u);
	            	dis1[u] = dis1[v] + 1;
	            	par[u] = v;
	         	}
	           
	        }
    	}
	}
}


ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int m;
	cin>>n>>m;

	vector<string>s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];

	}

	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++){
			if(s[i][j]=='#'){
				continue;
			}
			else if(s[i][j]=='.' || s[i][j]=='M' || s[i][j]=='A'){
				if(i-1>=0  && s[i-1][j]!='#'){adj[i*m+j+1].push_back(m*(i-1)+j+1);}
				if(i+1<n  && s[i+1][j]!='#'){adj[i*m+j+1].push_back(m*(i+1)+j+1);}
				if(j-1>=0   && s[i][j-1]!='#'){adj[i*m+j+1].push_back(m*i+j);}
				if(j+1<m   && s[i][j+1]!='#'){adj[i*m+j+1].push_back(m*i+j+2);}
			}
			if(s[i][j]=='M'){
				adj[0].push_back(m*i+j+1);
			}
			if(s[i][j]=='A'){
				s1 = i*m+j+1;
			}
		}

		

	}

	bfs();

	
	for(int i=0;i<=n*m;i++){
		used[i] = 0;
	}

	bfs1();
	
	int check = 0;
	
	for(int i=1;i<=n*m;i++){
		if(i%m==0 || i%m==1 || (i<=m && i>0) || (i>(n-1)*m && i<=n*m)){
			if(dis1[i]!=0){
				check = i;
			}
		}
	}

	if(check!=0){
		cout<<"YES\n";
		vector<char>path;
		int u = check,v;
		for (v = u; par[v] != -1; v = par[v]){
        	if(u-v==1)path.push_back('R');
        	else if(v-u==1)path.push_back('L');
        	else if(u-v==m)path.push_back('D');
        	else if(v-u==m)path.push_back('U');
        	u = v;
		}
		if(u-v==1)path.push_back('R');
        else if(v-u==1)path.push_back('L');
       	else if(u-v==m)path.push_back('D');
       	else if(v-u==m)path.push_back('U');

	    reverse(path.begin(), path.end());
	    cout<<path.size()<<'\n';
	    for (char v : path)
	        cout << v ;
	}
	else{
		cout<<"NO";
	}
	

}