#include <bits/stdc++.h>


 
#include <cmath> //abs, pow, sin, cos, tan
#include <string>//string
#include <iostream>
#include <sstream>
#include <algorithm>//min_element, max_element, __gcd(最大公約数), reverse, sort, lower_bound
#include <ctime>//rand, clock
#include <functional>//sort(greater<>)
#include <vector>//vector<int> vec
#include <stack>//stack
#include <queue>//queue
#include <map>//map
#include <set>
#include <bitset>
#include <unordered_set>


#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define yes() cout << "Yes" << endl
#define no() cout << "No" << endl
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
// cout << fixed << setprecision(表示する桁数)<< 小数

const vector<int> dxs = {1, 0, -1, 0};
const vector<int> dys = {0, 1, 0, -1};
const vector<int> dxs8 = {1, 0, -1, 0, -1, -1, 1, 1};
const vector<int> dys8 = {0, 1, 0, -1, -1, 1, -1, 1};
int inf = 1<<30;
ll INF = (1LL<<60);
ll mod = 998244353LL;
int h, w, n;

int f() {
    char c[109][109];
    int sx, sy, gx, gy, dist[109][109], kyori[109][109];
 
    rep1(i, h) rep1(j, w) {
        cin >> c[i][j];
        if (c[i][j] == 'S') {
            sx = i; sy = j;
        }
        if (c[i][j] == 'G') {
            gx = i; gy =  j;
        }
    }
    queue<pii> Q;
    rep1(i, h) rep1(j, w) dist[i][j] = -inf;
    rep1(i, h) rep1(j, w) kyori[i][j] = inf;
    dist[sx][sy] = kyori[sx][sy] = 0;
    Q.push({sx, sy});
    while(!Q.empty()) {
        int px = Q.front().first, py = Q.front().second; Q.pop();
        rep(i, 4) {
            int nx = px +dxs[i], ny = py + dys[i];
            if (nx == 0 || nx == h+1 || ny == 0 || ny == w+1 || kyori[px][py] >= kyori[nx][ny]) continue;
            int val;
            if (c[nx][ny] == 'G' ) val = 0;
            else val = c[nx][ny] - '0';
            chmax(dist[nx][ny], dist[px][py] + val);
            if (kyori[nx][ny] == inf){
                kyori[nx][ny] = kyori[px][py] + 1;
                Q.push({nx,ny});
            }    
            
        }
    }
    // rep1(i, h) {
    //     rep1(j, w) cout << dist[i][j] << ' ';
    //     cout << endl;
    // }

    return dist[gx][gy];
}
int main() {
    cin >> h >> w >> n;
    int res = 0;
    while(n--) {
        res += f();
        
    }

    cout << res << endl;
}
