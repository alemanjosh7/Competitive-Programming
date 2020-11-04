/*
ID: Joshi503
TASK: diamond
LANG: C++                 
*/
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
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000
#define INF 100000
#define pi atan(1)*4
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()	
 
#define EPS 1.0e-6
 
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll mcm(ll a, ll b) {return (a * b) / gcd(a, b);}  
bool comp(ll a, ll b) {return a > b;}  
   
int main(){
//	boost;	
	
	ofstream fout ("diamond.out");
	ifstream fin ("diamond.in");
    
    int n, k;
	
	fin >> n >> k;
	
	int dia[n];
	
	for(int i = 0; i < n; i++) fin >> dia[i];
	
	sort(dia, dia+n);
	
	int l = 0, c = 0, ans = -1, i = 0;
	
	while(true){
		while(dia[i]-dia[l] <= k && i < n){
			c++;
			i++;
		}
		ans = max(ans, c);
		c = 0;
		l++;
		i = l;
		if(i == n) break;
	}
	fout << ans << "\n";
	
	return 0;
}
