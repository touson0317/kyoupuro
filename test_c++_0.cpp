
//#include "atcoder/all"
//using namespace atcoder;
 
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
#include <unordered_set>
#include <iomanip>


#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define yes() cout << "Yes" << endl
#define no() cout << "No" << endl

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vpli = vector<pair<ll, int>>;
using vpil = vector<pair<int, ll>>;
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

long long Power(long long a, long long b, long long m) {
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		int wari = (1 << i);
		if ((b / wari) % 2 == 1) {
			Answer = (Answer * p) % m; // 「a の 2^i 乗」が掛けられるとき
		}
		p = (p * p) % m;
	}
	return Answer;
}

// a ÷ b を m で割った余りを返す関数
long long Division(long long a, long long b, long long m) {
	return (a * Power(b, m - 2, m)) % m;
}

// nCr mod 1000000007 を返す関数
long long ncr(int n, int r) {
	const long long M = mod;

	// 手順 1: 分子 a を求める
	long long a = 1;
	for (int i = 1; i <= n; i++) a = (a * i) % M;

	// 手順 2: 分母 b を求める
	long long b = 1;
	for (int i = 1; i <= r; i++) b = (b * i) % M;
	for (int i = 1; i <= n - r; i++) b = (b * i) % M;

	// 手順 3: 答えを求める
	return Division(a, b, M);
}

int n, m, k, even = 0, odd = 0;
vi G[200009];
int main () {
   cin >> n>> m>> k;
   rep1(i, m) {
    int u, v;
    cin  >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
   }
   rep1(i, n) {
    if ((int)G[i].size() %2 == 0) even++;
    else odd++;
   }
   ll res = 0;
   rep(i, min(odd, k)) {
      if (i %2 == 1) continue;
      int pos = k-i;
      if (pos < 0) continue;
      res = (res + (ncr(odd, i)*ncr(even,pos))%mod)%mod;
      //res = (res + (ncr(odd, i)*ncr(even,pos2))%mod)%mod;
   }

   rep(i, min(odd, n-k)) {
      if (i %2 == 1) continue;
      int pos = n-k-i;
      if (pos < 0) continue;
      res = (res + (ncr(odd, i)*ncr(even,pos))%mod)%mod;
      //res = (res + (ncr(odd, i)*ncr(even,pos2))%mod)%mod;
   }

   cout << res << endl;
} 
