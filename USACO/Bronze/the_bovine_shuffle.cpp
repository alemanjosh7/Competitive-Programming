#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef uint64_t u64;
typedef vector<ll> vl;
typedef vector<vl> bgraf;
typedef vector<int> vi;
typedef vector<vi> graf;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> wgraf;
typedef pair<ll,ll> bp;
typedef vector<bp> vbp;
typedef vector<vbp> ggraf;
 
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define pmod 1000000007
#define MOD 1000000
#define INF 100000
#define pi atan(1)*4
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()	
 
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll mcm(ll a, ll b) {return (a * b) / gcd(a, b);}  
bool comp(ll a, ll b) {return a > b;}

void solve(){
	ofstream fout ("shuffle.out");
    ifstream fin ("shuffle.in");

	int n;
	
	cin >> n;
	
	vector<int> a(n);
	vector<string> s(n);
	
	int needSh = 0;
	
	for(int i = 0; i < n*2; i++){
		if(i < n) cin >> a[i];
		else cin >> s[i%n];
		
		if(a[i] != i+1 && i < n) needSh++;
	}
	
	int shuffles = 0, i = 0;
	
	while(shuffles < needSh-1){
		if(a[i%n] != i % n+1){
			shuffles++;
			swap(s[a[i%n]-1], s[i%n]);
			swap(a[a[i%n]-1], a[i%n]);
		}
		i++;
	}
	
	for(int i = 0; i < n; i++){
		cout << s[i] << "\n";
	}
		
}
	  
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	
	ll t = 1;
//	cin >> t;
	while(t--)
		solve();
 
	return 0;
}
