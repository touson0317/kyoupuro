#include <bits/stdc++.h>

 
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
using namespace atcoder;
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
// cout << fixed << setprecision(表示する桁数)<< 小数
int n, m, a[100009], b[100009], c[100009];
vpii G[100009];

priority_queue<pii, vpii, greater<pii>> Q;
int cur[100009]; bool kakutei[100009];

int main() {
  cin >> n >> m;
  rep1(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    G[a[i]].push_back(make_pair(b[i], c[i]));
    G[b[i]].push_back(make_pair(a[i], c[i]));
  }
  
  rep1(i, n) {
    kakutei[i] = false;
    cur[i] = INT_MAX;
  }

  cur[1] = 0;
  Q.push(make_pair(cur[1], 1));

  while(!Q.empty()) {
    int pos = Q.top().second; Q.pop();

    if (kakutei[pos] == true) continue;

    kakutei[pos] = true;
    rep(i, G[pos].size()) {
      int nex = G[pos][i].first;
      int cost = G[pos][i].second;
      if (cur[nex] > cur[pos] + cost) {
        cur[nex] = cur[pos] + cost;
        Q.push(make_pair(cur[nex], nex));
      }
    }
  }

  rep1(i, n) cout << cur[i] << endl;

}