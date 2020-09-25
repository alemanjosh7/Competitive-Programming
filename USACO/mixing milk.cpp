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
	ofstream fout ("mixmilk.out");
    ifstream fin ("mixmilk.in");

	vl c(3), m(3);
	
	for(int i = 0; i < 3; i++){
		fin >> c[i] >> m[i];
	}
	
	ll ac = 100, i = 0;
	
	while(ac){
		
		ll temp = min(m[(i)%3], c[(i+1)%3] - m[(i+1)%3]);
		
		m[(i+1)%3] += temp;
		m[i%3] -= temp;
		
		i++;
		
		ac--;
	}
	
	for(int i = 0; i < 3; i++) fout << m[i] << "\n";
		
}
	  
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	
	ll t = 1;
//	cin >> t;
	while(t--)
		solve();
 
	return 0;
}
