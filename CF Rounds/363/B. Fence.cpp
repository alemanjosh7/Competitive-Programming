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

void solve() {

	int n, k;

	cin >> n >> k;

	vi h(n);

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	vi ps(n + 1, 0);

	for (int i = 0; i < n; i++) {
		ps[i + 1] = ps[i] + h[i];
	}

	int ind = 0, res = n - k, ans = INFI;

	for (int i = k - 1; i < n; i++) {
		if (ans > ps[i + 1] - ps[ind]) {
			res = i - k + 2;
			ans = ps[i + 1] - ps[ind];
		}
		ind++;
	}

	cout << res << "\n";

}

int main() {
	setIO("");

	int t = 1;

	//	cin >> t;

	while (t--)
		solve();

	return 0;
}

