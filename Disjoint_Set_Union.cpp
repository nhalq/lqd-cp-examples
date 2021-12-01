struct DSU{
   vector<int> par, cnt;
   DSU(int sz) {
      par.resize(sz); cnt.resize(sz);
   }
   int root(int u) { 
      if (!par[u]) return u;
      return par[u] = root(par[u]);
   }
   void connect(int u, int v) { 
      u = root(u); v = root(v);
      if (u == v) return;
      if (cnt[u] < cnt[v]) swap(u, v);
      cnt[u] += cnt[v]; par[v] = u;
   }
};
