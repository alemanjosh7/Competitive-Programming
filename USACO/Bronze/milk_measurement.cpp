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
typedef vector<ii> vpi;
typedef vector<vpi> wgraf;
 
#define F first 
#define S second 
#define PB push_back 
#define POPB pop_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define pmod 1000000007
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
#define INFL 1000000000000000000
#define INFI 1000000000
#define pi atan(1)*4
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()	
#define DBG(x) cerr << #x << " = " << x << endl;
#define salto "\n"
#define dbg cout << "test" << endl;
 
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
	
	map<pair<int, int>, int> m;
		
	int x = 0, y = 0, time = 1, res = 1e9;
	
	for(int i = 0; i < n; i++){
		char a; int b;
		cin >> a >> b;
		if(a == 'N'){
			for(int i = 0; i < b; i++){
				if(m[pair<int, int>(x, y)]){
					res = min(time - m[pair<int, int>(x, y)], res);
				}
				m[pair<int, int>(x, y)] = time;	
				time++;
				y++;
			}			
		}
		if(a == 'E'){
			for(int i = 0; i < b; i++){
				if(m[pair<int, int>(x, y)]){
					res = min(time - m[pair<int, int>(x, y)], res);
				}
				m[pair<int, int>(x, y)] = time;	
				time++;
				x++;
			}	
		}
		if(a == 'S'){
			for(int i = 0; i < b; i++){
				if(m[pair<int, int>(x, y)]){
					res = min(time - m[pair<int, int>(x, y)], res);
				}
				m[pair<int, int>(x, y)] = time;	
				time++;
				y--;
			}	
		}
		if(a == 'W'){
			for(int i = 0; i < b; i++){
				if(m[pair<int, int>(x, y)]){
					res = min(time - m[pair<int, int>(x, y)], res);
				}
				m[pair<int, int>(x, y)] = time;	
				time++;	
				x--;
			}	
		}
	}
	
	if(res == 1e9) cout << "-1\n";
	else cout << res << "\n";
	
}

int main(){
	setIO("mowing");

	int t = 1;	

//	cin >> t;

	while(t--)
		solve();
		
	return 0;
}
