#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n, m; cin >> n >> m;
  vector<string> a(n), b(m);
 for (auto& i : a) cin >> i;
 for (auto& i : b) cin >> i;
  int q; cin >> q;
 while(q--) {
  int y; cin >> y;
  cout << a[(y-1)%n] << b[(y-1)%m] << '\n';
 }
  return 0;
}