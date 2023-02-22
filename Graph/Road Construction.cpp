#include<bits/stdc++.h>

using namespace std;

#define MAX 992337203685477580
#define MIN -99233720368547750
#define MOD 1000000007
typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;

int rnk[100050];
int parent[100050];
int cmpnt,csize = 1;

void make_set(int v) {
    parent[v] = v;
    rnk[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        rnk[a] += rnk[b];

        csize = max(csize,rnk[a]);
        cmpnt--;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    cmpnt = n;

    for(int i=0;i<=n;i++)make_set(i);

    for(int i=0;i<m;i++){

        int x,y;
        cin>>x>>y;

        union_sets(x,y);

        cout<<cmpnt<<" "<<csize<<'\n';
    }
}