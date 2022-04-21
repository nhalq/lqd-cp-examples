/**
 * Disjoint-set Union
 * Author: camnguyenmeow
 * Date  : Dec 2, 2021
 */

struct DisjointSet {
	vector<int> parent, counts;
	DisjointSet(int _size) : parent(_size), counts(_size) {
		for (int i = 0; i < _size; ++i) {
			parent[i] = i;
		}
	}

	// Tìm parent's node của u //
	int p_lookup(int u) {
		if (u == parent[u]) {
			return u;
		}

		return parent[u] = p_lookup(parent[u]);
	}

	// Join 2 nodes lại với nhau //
	void join(int u, int v) {
		u = p_lookup(u);
		v = p_lookup(v);

		if (u != v) {
			if (counts[u] < counts[v]) {
				swap(u, v);
			}

			counts[u] += counts[v];
			parent[v] = u;
		}
	}
};
