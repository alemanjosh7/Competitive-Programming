#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef uint64_t u64;
typedef vector<ll> vl;
typedef vector<vl> bgraf;
typedef vector<int> vi;
typedef vector<vi> graf;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
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
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vi a;

vector<vi> adj;

void go(int l, int r, int x){
	int maxi = -1, ind;
	for(int i = l; i < r; i++){
		if(maxi < a[i]){
			maxi = a[i];
			ind = i;
		}
	}
	adj[x].push_back(maxi);
	go(l, ind, maxi);
	go(ind, r, maxi);
}

void solve() {

	int n;

	cin >> n;

	a.resize(n);
	adj.resize(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}

	go(0, n, n - 1);

	for(int i = 0; i < n; i++){
		cout << i << ": ";
		for(auto u : adj[i]){
			cout << u << " ";
		}
		cout << "\n";
	}

	
}

int main() {
	setIO("");

	int t = 1;

	cin >> t;

	while (t--)
		solve();

	return 0;
}

