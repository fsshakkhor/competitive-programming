#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             2e16
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>


#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())


#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);


const int maxnodes = 5005;

int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];

struct Edge {
  int to, rev;
  int f, cap;
};

vector<Edge> g[maxnodes];

void addEdge(int s, int t, int cap)
{
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, 0};
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs()
{
  fill(dist, dist + nodes, -1);

  dist[src] = 0;
  int index = 0;
  q[index++] = src;

    for (int i = 0; i < index; i++)
    {
        int u = q[i];
        for (int j = 0; j < (int) g[u].size(); j++)
        {
            Edge &e = g[u][j];
            if (dist[e.to] < 0 && e.f < e.cap)
            {
                dist[e.to] = dist[u] + 1;
                q[index++] = e.to;
            }
        }
    }
  return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {
  if (u == dest)
    return f;

  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    Edge &e = g[u][i];

    if (e.cap <= e.f) continue;

    if (dist[e.to] == dist[u] + 1)
    {
      int flow = dinic_dfs(e.to, min(f, e.cap - e.f));
      if (flow > 0)
      {
        e.f += flow;
        g[e.to][e.rev].f -= flow;
        return flow;
      }
    }
  }
  return 0;
}

int maxFlow(int _src, int _dest)
{
    src = _src;
    dest = _dest;
    int result = 0;
    while (dinic_bfs())
    {
        fill(work, work + nodes, 0);
        while (int delta = dinic_dfs(src, INT_MAX))
            result += delta;
    }
    return result;
}

int main()
{
    FastRead
    int n,m;
    cin >> n >> m;
    FOR(i,1,m)
    {
        int a,b,c;
        cin >> a >> b >> c;
        addEdge(a-1,b-1,c);
        addEdge(b-1,a-1,c);
    }
    cout << maxFlow(0,n-1) << "\n";
}
