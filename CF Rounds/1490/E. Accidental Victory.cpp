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

	int n;

	cin >> n;

	vi a(n);

	for (int i = 0; i < n; i++) cin >> a[i];

	sort(all(a));

	vi ps(n + 1, 0);

	for (int i = 0; i < n; i++) {
		ps[i + 1] = ps[i] + a[i];
	}

	vi res;

	for (int i = n - 1; i >= 0; i--) {
		cout << "1. " << ps[i] + a[i] << "\n";
		cout << "2. " << ps[n] - ps[i + 1] << "\n";
		// cout << ps[i] + a[i] << " " << ps[n] - ps[i + 1] << "\n";
		if (ps[i] + a[i] >= ps[n] - ps[i + 1]) {
			res.PB(i + 1);
		}
	}

	cout << "\n";

	sort(all(res));

	cout << sz(res) << "\n";

	for (int i = 0; i < sz(res); i++) {
		cout << res[i] << " ";
	}

	cout << "\n\n";

}

int main() {
	setIO("");

	int t = 1;

	cin >> t;

	while (t--)
		solve();

	return 0;
}

