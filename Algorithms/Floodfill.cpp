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
#define yes cout<<"Yes\n"
#define no cout<<"No"
#define y2 _y2
#define y1 _y1
#define x1 _x1
#define x2 _x2

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

const int MAXN = 1005, MAXM = 1005;

int grid[MAXN][MAXM];

int n, m;

bool visited[MAXN][MAXM];

int currentSize = 0;

void floodfill(int r, int c, int color){
	if(r < 0 || r >= n || c < 0 || c >= m) return;
	if(grid[r][c] != color) return;
	if(visited[r][c]) return;
	visited[r][c] = 1;
	currentSize++;
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r + 1, c, color);
	floodfill(r - 1, c, color);
	
}

void solve(){
 
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int color;
			cin >> color;
			grid[i][j] = color;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j]){
				currentSize = 0;
				floodfill(i, j, grid[i][j]);
			}
		}
	}	
	
	
}

int main(){
	
	setIO("");

	int t = 1;	

//	cin >> t;

	while(t--)
		solve();
		
	return 0;
}
