#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
set<int> adj[maxn]; 
int n, sub[maxn]; 
char col[maxn];

void dfs(int u, int par) {
	sub[u] = 1;
	for(int v : adj[u]) if(par - v) {
		dfs(v, u); sub[u] += sub[v];
	}
}
int centroid(int u, int par, int sz) {
	for(int v : adj[u]) if(par - v)
		if(sub[v] > sz)
			return centroid(v, u, sz);
	return u;
}
void decompose(int u, int par, char rank) {
	dfs(u, -1);
	int c = centroid(u, -1, sub[u] / 2);
	col[c] = rank;
	for(int v : adj[c]) {
		adj[v].erase(c);
		decompose(v, c, rank+1);
	}
}
int main () {
	cin>>n; 
	for(int i=0; i<n-1; i++) {
		int u, v; cin>>u>>v; 
		u--, v--;
		adj[u].insert(v);
		adj[v].insert(u);
	} 
	decompose(0, -1, 'A');
	for(int i=0; i<n; i++) 
		cout<<col[i]<<" ";
}
