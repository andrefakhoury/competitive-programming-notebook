#include <bits/stdc++.h>

class DSU_partial {
public:
	int n, time;
	std::vector<int> par, sz, tim;

	// Union Find with union by size.
	// "Partially persistent": past states can be seen, but not modified
	// operations in O(log(n))
	DSU_partial(int n) : n(n) {
		par.resize(n + 1);
		tim.resize(n + 1);
		sz = std::vector<int>(n + 1, 1);
		iota(par.begin(), par.end(), 0);
	}

	// find leader of current component on time t
	int find(int x, int t = INT_MAX) {
		return par[x] == x || tim[x] > t ? x : find(par[x], t);
	}

	// merge two componnets
	// returns whether they dont already belong to the same
	inline bool merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;

		if (sz[u] > sz[v]) std::swap(u, v);
		par[u] = v;
		tim[u] = ++time;
		sz[v] += sz[u];
		return true;
	}
};