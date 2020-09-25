#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define dbg cerr << "HU" << endl;
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
 
typedef long long tint;
typedef long double ld;
 
const int INF = 190000000;
const int MOD = 1000000007;
const int MAXN = 500001;
 
int main(){
    ifstream cin("gymnastics.in");
    ofstream cout("gymnastics.out");
    int k, n;
    cin >> k >> n;
    vector<vector<int>> cont (n+1, vector<int> (n+1, 0));
    //esta matriz me dice en cuantas filas la vaca i esta antes que la vaca j
    for(int i=0;i<k;i++){
        vector<int> vacas (n);
        for(int j=0;j<n;j++){
            cin >> vacas[j];
        }
        for(int j=0;j<n;j++){//la j = 4
            for(int k=0;k<j;k++){ 
                cont[vacas[k]][vacas[j]]++;
                //yo sé que la vaca k, esta antes que la vaca j, por lo tanto, la vaca k le gana a la vaca j
            }
        }
    }
    int respuesta = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(cont[i][j] == k){
                respuesta++;
            }
        }
    }
    cout << respuesta << endl;
}
