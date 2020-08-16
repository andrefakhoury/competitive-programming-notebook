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
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 251, INF = 0x3f3f3f3f;

int dist[MAXN][MAXN];

int main() {
	int n, m; rd(n, m);
	mset(dist, INF);

	for (int i = 0; i < m; i++) {
		int u, v, w; rd(u, v, w);
		dist[u][v] = min(w, dist[u][v]);
		dist[v][u] = min(w, dist[v][u]);
	}

	for (int u = 1; u <= n; u++) {
		dist[u][u] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
			}
		}
	}

	int ans = INF;
	for (int u = 1; u <= n; u++) {
		int cur = 0;
		for (int v = 1; v <= n; v++) {
			cur = max(cur, dist[u][v]);
		}
		ans = min(ans, cur);
	}

	printf("%d\n", ans);
}