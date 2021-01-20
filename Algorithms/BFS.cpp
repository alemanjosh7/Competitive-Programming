#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void bfs(int node){
	queue<int> q;

	visited[node] = true;

	q.push(node);
	
	while(!q.empty()){
		int node = q.front(); q.pop();
		cout << "Checking adjacent vertices for vertex: " << node << "\n";
		for(auto v : adj[node]){
			if(!visited[v]){
				cout << "Visit and enqueue " << v << "\n";
				visited[v] = 1;
				q.push(v);
			}
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
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			bfs(i);
		}
	}

	return 0;
}
