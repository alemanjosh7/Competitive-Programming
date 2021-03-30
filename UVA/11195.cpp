//credits: Benq
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using grafo = vector<vi>;

#define tcT template<class T
#define tcTU tcT, class U

tcT> using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using PR = pair<T, T>;

#define mp make_pair

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT > int lwb(V<T>& a, const T& b) { return int(lb(all(a), b) - bg(a)); }

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

#define francesco_bernoulli ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define DBG(x) cerr << #x << " = " << x << endl;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
    return x == 0 ? 0 : 31 - __builtin_clz(x);
} // floor(log2(x)) 
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down

tcT > bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
tcT > bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

tcT > void remDup(vector<T>& v) { // sort and remove duplicates
    sort(all(v)); v.erase(unique(all(v)), end(v));
}

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return (a.second < b.second);
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

vs g;
vb sum, dif, c;
int ans = 0;
int n;

void dfs(int r) { // place queen in r-th row
    if (r == n) {
        ++ans; // found valid placement
        return;
    }
    for (int i = 0; i < n; ++i)
        if (g[r][i] == '.' && !c[i] && !sum[i + r] && !dif[i - r + n - 1]) {
            c[i] = sum[i + r] = dif[i - r + n - 1] = 1;
            dfs(r + 1);
            c[i] = sum[i + r] = dif[i - r + n - 1] = 0;
        }
}

void solve() {
    vi res;
    while (1) {
        cin >> n;
        if (!n) break;
        sum.assign(n * 2 + 10, 0);
        dif.assign(n * 2 + 10, 0);
        c.assign(n + 10, 0);
        g.resize(n + 10);
        for (int i = 0; i < n; ++i) cin >> g[i];
        dfs(0);
        res.push_back(ans);
        ans = 0;
        sum.clear();
        c.clear();
        dif.clear();
        g.clear();
    }

    F0R(i, sz(res)) cout << "Case " << i + 1 << ": " << res[i] << "\n";

}

int main() {

    francesco_bernoulli;

    int t = 1;

    // cin >> t;

    while (t--)
        solve();

    return 0;
}

