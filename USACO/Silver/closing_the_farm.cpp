#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef uint64_t u64;
typedef vector<ll> vl;
typedef vector<vl> bgraf;
typedef vector<int> vi;
typedef vector<vi> graf;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vpi;
typedef vector<vpi> wgraf;
 
#define F first 
#define S second 
#define PB push_back 
#define POPB pop_back
#define MP make_pair
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
#define INFL 1000000000000000000
#define INFI 1000000000
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define leastbit(x) __builtin_ffs(x)
#define pi atan(1)*4
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()	
#define DBG(x) cerr << #x << " = " << x << endl;
#define salto "\n"
#define msz(a) memset(a, 0, sizeof a);

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}	

vector<vi> adj;
vector<bool> visited;

void dfs(int node){
	visited[node] = true;
	for(auto u : adj[node]){
		if(!visited[u] ){
			dfs(u);
		}
	}
}

void solve(){

	int N, M;
	
	cin >> N >> M;

	adj.resize(N + 1);
	
	for(int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	vi order(N);
	
	vector<bool> pasador(N + 1, 0);
	
	for(int i = 0; i < N; i++){
		cin >> order[i];
		visited = pasador;
		pasador[order[i]] = 1;
		dfs(order[i]);
		bool can = 1;
		for(int j = 1; j <= N; j++){
			if(!visited[j]) can = 0;
		}
		if(can) cout << "YES\n";
		else cout << "NO\n";
		
	}

}

int main(){
	setIO("closing");

	int t = 1;	

//	cin >> t;

	while(t--)
		solve();
		
	return 0;
}
