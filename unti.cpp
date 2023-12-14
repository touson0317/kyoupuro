
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

int ind[250009], p[250009];
ll  dp[250009], unti[250009], diff;
vi G[250009];
int n;
    
ll a[250009], after[250009];
bool visited[250009];
void dfs(int pos) {
    visited[pos] = true;
    for (auto nex: G[pos]) {
        if (!visited[nex]) dfs(nex);
    }
}
int main () {
    
    cin >> n;
    rep1(i, n) cin >> a[i];
    rep2(i, 2, n+1) {
        cin >> p[i];
        G[p[i]].push_back(i);
        ind[p[i]]++;
    }
    dfs(1);
    rep1(pos, n) {
        if (!visited[pos]) continue;
        for (auto nex: G[pos]) if (visited[nex]) dp[nex] = max(dp[nex], dp[pos]+1LL);
    }
    rep1(i, n) {
        unti[(int)dp[i]] += a[i];
    }
    for (int i = n; i >= 1; i--) {
        if (unti[i] == 0) continue;
        diff = unti[i];
        break;
    }
  

    if (diff == 0) {
        if (a[1] == 0) cout << 0 << endl;
        else if (a[1] > 0) cout << '+' << endl;
        else cout << '-' << endl;
    }
    else if (diff > 0) cout << '+' << endl;
    else cout << '-' << endl;
} 
