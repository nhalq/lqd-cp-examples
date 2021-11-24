// Segment Tree Lazy Sum
struct SegmentTree {
	vector<long long> sum;
	vector<int> lazy;
	int n;

	SegmentTree(int _n = 0){
		n = _n;
		sum.assign(4*n + 7, 0);
		lazy.assign(4*n + 7, 0);
	}

	void pushDown(int i, int l, int r) {
		int m = (l + r) / 2;
		sum[2*i] += 1LL * lazy[i] * (m - l + 1); 
		sum[2*i + 1] += 1LL * lazy[i] * (r - m); 
		lazy[2*i] += lazy[i];
		lazy[2*i + 1] += lazy[i];
		lazy[i] = 0; 
	}

	long long getSum(int i, int l, int r, int u, int v) {
		if (l > v || r < u || l > r || v < u) return 0;

		if (u <= l && r <= v) return sum[i];

		pushDown(i, l, r);
		int m = (l + r) / 2;
		long long L = getSum(2 * i, l, m, u, v);
		long long R = getSum(2 * i + 1, m + 1, r, u, v);
		return L + R;
	}

	void update(int i, int l, int r, int u, int v, int c) {
		if (l > v || r < u || l > r || v < u) return;

		if (u <= l && r <= v) {
			lazy[i] += c;
			sum[i] += 1LL * c * (r - l + 1);
			return;
		}

		pushDown(i, l, r);
		int m = (l + r) >> 1;
		update(2 * i, l, m, u, v, c);
		update(2 * i + 1, m + 1, r, u, v, c);

		sum[i] = sum[2 * i] + sum[2 * i + 1];
	}

	long long getSum(int l, int r) {
		return getSum(1, 1, n, l, r);
	}
	void update(int l, int r, int c) {
		update(1, 1, n, l, r, c);
	}
};