#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];
int cost[MAXN];
int a[MAXN];
int b[MAXN];
ll ans;

pii dfs(int u, int p, int w) {
	pii ret = {0, 0};
	if (a[u] != b[u]) {
		ret.fi += a[u];
		ret.se += b[u];
	}
	for (int v : edges[u]) if (v != p) {
		pii cur = dfs(v, u, min(w, cost[u]));
		ret.fi += cur.fi;
		ret.se += cur.se;
	}
	if (cost[u] < w) {
		int q = min(ret.fi, ret.se);
		ans += q * 2ll * cost[u];
		ret.fi -= q;
		ret.se -= q;
	}
	return ret;
}

int main() {
	int n; rd(n);
	for (int i = 1; i <= n; i++)
		rd(cost[i], a[i], b[i]);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
		edges[v].pb(u);
	}
	pii ret = dfs(1, -1, INT_MAX);
	if (ret.fi != ret.se)
		puts("-1");
	else
		printf("%lld\n", ans);
}