struct edge{
   int u, v, w; // Cạnh (u, v) có trọng số là w
};
int root(int u) {
   if (!par[u]) return u;
   return par[u] = root(par[u]);
}
bool connect(int u, int v) {
   u = root(u); v = root(v);
   if (u == v) return false;
   if (cnt[u] < cnt[v]) swap(u, v);
   cnt[u] += cnt[v]; par[v] = u;
   return true;
}
int minimum_spanning_tree(vector<edge> edge_list) {
   int res = 0;
   sort(edge_list.begin(), edge_list.end(), [&] (const edge& X, const edge& Y) {return X.z < Y.z;});
   for (edge i : edge_list) {
      if (connect(i.u, i.v)) continue;
      res += i.w;
   }
   return res;
}
