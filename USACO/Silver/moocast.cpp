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

int count = 0;

int dfs(int node){
	int count = 1;
	
	visited[node] = true;
	
	for(auto u : adj[node]){
		if(!visited[u]){
			count += dfs(u);
		}
	}
	return count;
}

int dist(pair<int, int> a, pair<int, int> b){
	int x1 = a.F, x2 = b.F, y1 = a.S, y2 = b.S;
	return ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); 
}

void solve(){

	int N;
	
	cin >> N;

	adj.resize(N + 1);
	
	vector<pair<pair<int, int>, pair<int, int>>> cows;
	
	for(int i = 0; i < N; i++){
		int x, y, r;
		cin >> x >> y >> r;
		cows.PB({{x, y}, {r, i}});
	}
	
	for(auto x : cows){
		for(auto y : cows){
			if(x == y) continue;
			pair<int, int> cow1 = {x.F.F, x.F.S};
			pair<int, int> cow2 = {y.F.F, y.F.S};
			int r1 = x.S.F;
			if(dist(cow1, cow2) <= r1 * r1){
				adj[x.S.S].PB(y.S.S);
			}
		}
	}
	
	int ans = 1;
	
	for(int i = 0; i < N; i++){
		visited.assign(N, 0);
		int node = dfs(i);
//		cout << i << " " << node << "\n";
		ans = max(ans, node);
	}
	
	cout << ans << "\n";

}

int main(){
	setIO("");

	int t = 1;	

//	cin >> t;

	while(t--)
		solve();
		
	return 0;
}
