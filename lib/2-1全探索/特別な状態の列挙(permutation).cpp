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

const int MAX_N = 10;
bool used[MAX_N];
int perm[MAX_N], perm2[MAX_N];
// {0,1,2 ..., n-1}の並び替えN!通り生成する。

void permutation1 (int pos, int n) {
  if (pos == n) {
    /*
    permに対する操作
    */
    return;
  }
  rep(i, n) {
    if (!used[i]) {
      perm[pos] = i;
      used[i] = true;
      permutation1(pos+1, n);
      used[i] = false; 
    }
  }
  return;
}

//重複があってもすべての順列を作成する。
void permutation2 (int n) {
  rep(i, n) {
    perm2[i] = i;
  }
  do {
    /*
    perm2に対する捜査
    */
  } while (next_permutation(perm2, perm2+n));
  //すべての順列を生成し終わったらnext_permutationはfalseを返す。
  return ;
}