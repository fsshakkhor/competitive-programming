#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, long long> pll;
struct CostFlow {
  static const int MXN = 10005;
  static const long long INF = 102938475610293847LL;
  struct Edge {
    int v, r;
    long long f, c;
  };
  int n, s, t, prv[MXN], prvL[MXN], inq[MXN];
  long long dis[MXN], fl, cost;
  vector<Edge> E[MXN];
  void init(int _n, int _s, int _t) {
    n = _n; s = _s; t = _t;
    for (int i = 0; i < n; i++) E[i].clear();
    fl = cost = 0;
  }
  void AddEdge(int u, int v, long long f, long long c) {
    E[u].push_back({v, (int) E[v].size()  , f,  c});
    E[v].push_back({u, (int) E[u].size()-1, 0, -c});
  }
  pll flow() {
    while (true) {
      for (int i=0; i<n; i++) {
        dis[i] = INF, inq[i] = 0;
      }
      dis[s] = 0;
      queue<int> q({s});
      while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for (int i = 0; i < E[u].size(); i++) {
          int v = E[u][i].v;
          long long w = E[u][i].c;
          if (E[u][i].f > 0 && dis[v] > dis[u] + w) {
            prv[v] = u; prvL[v] = i;
            dis[v] = dis[u] + w;
            if (!inq[v]) {
              inq[v] = 1;
              q.push(v);
            }
          }
        }
      }
      if (dis[t] == INF) break;
      long long tf = INF;
      for (int v = t, u, l; v != s; v = u) {
        u = prv[v]; l = prvL[v];
        tf = min(tf, E[u][l].f);
      }
      for (int v = t, u, l; v != s; v =u) {
        u = prv[v]; l = prvL[v];
        E[u][l].f -= tf;
        E[v][E[u][l].r].f += tf;
      }
      cost += tf * dis[t];
      fl += tf;
    }
    return {fl, cost};
  }
}flow;

const int N = 10010;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, k, x[N], y[N], t[N];
map <int, map <int, int>> g;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    scanf("%d %d %d", x + i, y + i, t + i);
    g[x[i]][y[i]] = i;
  }
  int src = 0, med = k + 1, snk = k + 2;
  CostFlow mcmf;
  mcmf.init(1 + k + 1 + 1, src, snk);
  mcmf.AddEdge(src, med, n, 0);
  for (int i = 1; i <= k; ++i) {
    if ((x[i] + y[i]) & 1) {
      mcmf.AddEdge(med, i, 1, -t[i]);
      mcmf.AddEdge(i, snk, 1, 0);
    } else {
      mcmf.AddEdge(med, i, 1, 0);
      mcmf.AddEdge(i, snk, 1, -t[i]);
    }
  }
  for (int i = 1; i <= k; ++i) {
    if ((x[i] + y[i]) % 2 == 0) continue;
    for (int j = 0; j < 4; ++j) {
      int px = x[i] + dx[j], py = y[i] + dy[j];
      if (g.find(px) != g.end() and g[px].find(py) != g[px].end()) {
        mcmf.AddEdge(i, g[px][py], N, 0);
      }
    }
  }
  cout << -mcmf.flow().second << '\n';
  return 0;
}
