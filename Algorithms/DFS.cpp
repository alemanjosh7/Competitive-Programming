#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node){
	visited[node] = true;
	for(int u : adj[node]){
		if(!visited[u]){
			dfs(u);
			cout << node << " apunta a: " << u << "\n";
		}
	}
}

int main(){
	
	int n, m;
	
	cin >> n >> m;
	
	adj.resize(n + 1); 
	visited.resize(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int componentes = 0;
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			componentes++;
			dfs(i);
		}
	}
	
	cout << "componentes: " << componentes << "\n";
	return 0;
}
