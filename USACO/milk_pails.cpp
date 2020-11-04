/*
ID: Joshi503
TASK: pails
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

int fill(int x, int y, int m){
	int ans1 = 0, ans2 = 0;
	
	int i = 1, k = m;
	
	while(m >= x){
		if(m % y == 0) return k;
		m -= x;
		ans1 += x;
	}
	
	m = k;
	
	int ans3 = 0, z = m/y, res = 0;
	for(int i = 1; i <= z; i++){
		res += (y*i);
		m -= res;	
		ans3 = max(ans3, ((m/x)*x+res));
		m = k;
		res = 0;
	}
	
	return max(ans1, ans3);
}
   
int main(){
//	boost;	
	
	ofstream fout ("pails.out");
	ifstream fin ("pails.in");
    
	int m, x, y;
	
	fin >> x >> y >> m;
	
	int a = (m/(x+y))*(x+y);
	int b = a;
	if(a+x <= m){
		a += ((m-a)/x)*x;
	}
	if(b+y <= m){
		b += ((m-b)/y)*y;
	}
	 
	
	fout << max({fill(x, y, m), fill(y, x, m), a, b }) << "\n";
	
	return 0;
}
