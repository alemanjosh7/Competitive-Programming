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

vector<pair<ll, ll>> dir;

ll x1 = 1e16, x2 = -1, y1 = 1e16, y2 = -1;

ll dfs(int node){
	
	visited[node] = 1;
	
	x1 = min(dir[node].F, x1);
	x2 = max(dir[node].F, x2);
	y1 = min(dir[node].S, y1);
	y2 = max(dir[node].S, y2);
	
	for(auto u : adj[node]){
		if(!visited[u]) dfs(u);
	}
	
	return llabs(x1 - x2) * 2 + llabs(y1 - y2) * 2;
	
}

void solve(){
 
	int n, m;
	
	cin >> n >> m;
	
	dir.resize(n + 1);
	
	for(int i = 0; i < n; i++){
		ll x, y;
		cin >> x >> y;
		dir[i + 1] = {x, y};
	}
	
	adj.resize(n + 1);
	visited.resize(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	ll ans = 1e16;
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			x1 = 1e16, x2 = -1, y1 = 1e16, y2 = -1;
			ans = min(dfs(i), ans);
		}
	}
	
	cout << ans << "\n";
		
}

int main(){
	
	setIO("fenceplan");

	int t = 1;	

//	cin >> t;

	while(t--)
		solve();
		
	return 0;
}
