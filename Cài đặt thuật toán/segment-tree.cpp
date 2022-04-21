// Segment Tree max
struct SegmentTree{
	vector<int> val;
    int n;

    SegmentTree(int _n = 0){
		n = _n;
		val.assign(4*n + 1, 0);
	}

	void update(int i, int l, int r, int x, int v){
		if(l == r){
			val[i] = v; return;
		}

		int m = (l + r)/2;
		if (x > m) update(2*i + 1, m + 1, r, x, v);
		else update(2*i, l, m, x, v);
		val[i] = max(val[2*i], val[2*i + 1]);
	}

	int getMax(int i, int l, int r, int u, int v) const{
		if(l > v || r < u || l > r || v < u) return -INF;

		if(u <= l && r <= v) return val[i];

		int m = (l + r) / 2;
		int L = getMax(2*i, l, m, u, v);
		int R = getMax(2*i + 1, m + 1, r, u, v);
		return max(L, R);
	}

	void update(int x, int v){
		update(1, 1, n, x, v);
	}
	int getMax(int l, int r) const{
		return getMax(1, 1, n, l, r);
    }
};