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
 	  
int main(){
	
	char s[100005];
	
	while(scanf("%s", s) != EOF){
		int sz = strlen(s);
		list<char> l;
		list<char> :: iterator it = l.begin();
		
		for(int i = 0; i < sz; i++){
			if(s[i] == '[') it = l.begin();
			else if(s[i] == ']') it = l.end();
			else l.insert(it, s[i]);
		}
		
		for(auto x : l) cout << x;
		
		cout << "\n";
		l.clear();
	}
 
	return 0;
}
