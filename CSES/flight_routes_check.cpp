#include<bits/stdc++.h>

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
#define yes cout<<"Yes\n"
#define no cout<<"No"
#define y2 _y2
#define y1 _y1
#define x1 _x1
#define x2 _x2

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

vector<vi> adj;
vector<bool> visited;

int dfs(int node){
	int count = 1;
	visited[node] = true;
	for(auto u : adj[node]){
		if(!visited[u]) count += dfs(u);
	}
	return count;
}

void solve(){
 
	int n, m;
	
	cin >> n >> m;
	
	adj.resize(n + 1);
	visited.resize(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].PB(v);
	}
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			cout << dfs
		}
	}	
	
	cout << "YES\n";
}

int main(){
	
	setIO("");

	int t = 1;	

//	cin >> t;

	while(t--)
		solve();
		
	return 0;
}
