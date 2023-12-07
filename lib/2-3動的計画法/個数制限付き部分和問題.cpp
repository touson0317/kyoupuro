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

const int MAX_N=109, MAX_M, MAX_W, MAX_K = 100009;

int dp[MAX_N][MAX_K]; //dp[i+1][j]: i番目まででjを作る際に余る最大のi番目の個数

void solve() {
  rep(i, n+1) rep(j, k+1) dp[i][j] = -1;
  dp[0][0] = 0;
  rep(i, n) rep(j, k+1) {
    if (dp[i][j] >= 0) {
      dp[i+1][j] = m[i];
    }
    else if (j < a[i] || dp[i+1][j-a[i] <= 0]) dp[i+1][j] = -1;
    else dp[i+1][j] = dp[i+1][j-a[i]] -1;
  }
  if (dp[k] >= 0) yes();
  else no();
}
