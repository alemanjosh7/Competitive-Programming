/*
ID: Joshi503
TASK: milk2
LANG: C++                 
*/
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using VT = vector<T>;

void _read(int &x){ scanf("%d", &x); }
void _read(ll &x){ scanf("%lld", &x); }
void _read(char *x){ scanf("%s", x); }
void _read(char &x){ scanf(" %c", &x); }
void _read(double& x){ scanf("%lf", &x); } 
void _read(string& x){ cin >> x; }         
 
template <typename T, typename U>
void _read(pair<T,U>& p){
	_read(p.fst); _read(p.snd);
}
 
template <typename T>
void _read(VT<T> &V){
	for(int i = 0; i < sz(V); i++) _read(V[i]);
}
 
void read() {}
template <typename T, typename... U>
void read(T &head, U &... tail){
	_read(head);
	read(tail...);
}
 
template <typename T>
void reada(T *arr, int n){
	for(int i = 0; i < n; i++) _read(arr[i]);
}

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void solve(){
	
	int n;
	
	cin >> n;
	
	vector<bool> v(1e6+10, 0);
	
	int inicio = 1e9, final = -1;
	
	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		r--;
		inicio = min(inicio, l), final = max(final, r);
		for(int j = l; j <= r; j++){
			v[j] = 1;
		}
	}
	
	int maxi = 0, mini = 0, count = 0, count1 = 0;
	
	for(int i = inicio; i <= final; i++){
		if(v[i]){
			count++;
			mini = max(mini, count1);
			count1 = 0;
		}
		else{
			count1++;
			maxi = max(maxi, count);
			count = 0;
		}
	}
	
	mini = max(mini, count1);
	maxi = max(maxi, count);
	
	cout << maxi  << " " << mini << "\n";
	
}

int main(){

	setIO("milk2");

	int t = 1;	

//	cin >> t;

	while(t--)
		solve();
		
	return 0;
}
