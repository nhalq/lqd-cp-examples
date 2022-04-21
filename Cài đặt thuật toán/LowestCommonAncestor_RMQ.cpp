/*   /\_/\     LCA trên cây gồm n đỉnh, gốc root
    (= ._.)    h[i] là độ cao của đỉnh i
    / >?  \>$  par[i][j] là tổ tiên thứ 2^j của đỉnh i
               a[i] là danh sách kề của đỉnh i
*/
int n, root;
int h[100005], par[100005][30];
vector<int> a[100005];

void dfs(int u) {
   for (int v : a[u])
   if (v != par[u][0]) {
      par[v][0] = u;
      h[v] = h[u]+1;
      dfs(v);
   }
}
void build() {
   for (int i = 1, maxi = log2(n); i <= maxi; ++i)
      for (int j = 1; j <= n; ++j)
         par[j][i] = par[par[j][i-1]][i-1];
}
int LCA(int u, int v) {
   if (h[u] > h[v]) swap(u, v);
   int maxi = log2(h[v]);
   for (int i = maxi; i >= 0; --i)
      if (h[v] - (1<<i) >= h[u])
         v = par[v][i];
   if (u == v) return u;
   for (int i = maxi; i >= 0; --i)
      if (par[u][i] != par[v][i]) {
         u = par[u][i]; v = par[v][i];
      }
   return par[u][0];
}
int main()
{
   h[root] = 0; par[root][0] = root;
   dfs(root);
   build();
}
