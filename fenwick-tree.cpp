// Fenwick Tree Max
struct FenwickTree {
	vector<int> val;
	int n;

	FenwickTree(int _n = 0){
		n = _n;
		v.assign(n + 7, -INF);
	}

	void update(int x, int c){ 
		for(; x <= n; x += x & -x) maximize(val[x], c);
	}

	int getMax(int x) const{ 
		int res = -INF;
		for(; x >= 1; x -= x & -x) maximize(res, val[x]);
		return res;
	}
};