#include <bits/stdc++.h>
//#include <atcoder/all>

 
#include <cmath> //abs, pow, sin, cos, tan
#include <string>//string
#include <iostream>
#include <algorithm>//min_element, max_element, __gcd(最大公約数), reverse, sort, lower_bound
#include <ctime>//rand, clock
#include <functional>//sort(greater<>)
#include <vector>//vector<int> vec
#include <stack>//stack
#include <queue>//queue
#include <map>//map
#include <set>
#include <bitset>


#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define yes() cout << "Yes" << endl
#define no() cout << "No" << endl
#define ALL(a) (a).begin(),(a).end()

using namespace std;
//using namespace atcoder;
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

const int inf = 1<<30, MAX_N = 109,MAX_M = 109;
char maze[MAX_N][MAX_M+1];
int n, m, gx, gy, sx, sy;

int d[MAX_N][MAX_M];

int bfs() {
  queue<int> Q;
  rep(i, n) rep(j, m) d[i][j] = inf;

  Q.push(pii(sx, sy));
  d[sx][sy] = 0;

  while(Q.size()) {
    pii pos = Q.front(); Q.pop();
    if (pos.first == gx && pos.second == gy) break;

    rep(i, 4) {
      int nx = pos.first + dxs[i], ny = pos.second + dy[i];

      if (0 <= nx && nx < n && 0 <= ny && ny < m && maza[nx][ny] !=' #' && d[nx][ny] == inf) {
        Q.push(pii(nx, ny));
        d[nx][ny] = d[pos.first][pos.second] + 1;
      }
    }
  }
  return d[gx][gy];
}