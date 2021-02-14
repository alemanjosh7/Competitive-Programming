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

vi f(int x) {
	vi a;
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			x /= i;
			a.PB(x);
		}
	}
	if (x > 1) a.PB(x);
	return a;
}

void solve() {

	int n; cin >> n;

	n <<= 1;

	vi a(n);

	for (int i = 0; i < n; i++) cin >> a[i];

	map<int, int> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int g = __gcd(a[i], a[j]);
			if (g > 1) {
				m[g]++;
			}
		}
	}

	int maxi = -1, num;

	for (auto x : m) {
		if (x.S > maxi) {
			maxi = x.S;
			num = x.F;
		}
	}
	vector<bool> taken(n + 10, 0);
	int count = 0;

	cout << maxi << " " << num << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (!taken[i] && !taken[j] && __gcd(num, a[i] + a[j]) > 1) {
				taken[i] = 1;
				taken[j] = 1;
				cout << i + 1 << " " << j + 1 << "\n";
				count++;
				if (count == n / 2 - 1) return;
			}
		}
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

