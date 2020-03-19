#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             1e9
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

#ifdef VAMP
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cout << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cout.write(names, comma - names) << " = " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif

const int N = 100005;
int n , m , q;
vector<pii>g[N];
vector<int>G[N];
set<int>par[N];

struct Point
{
    int name,val;
    bool operator <(const Point &p) const
    {
        return p.val < val;
    }
};

int dis[N];
bool vis[N];
void dijkstra(int source){
    for(int i = 0;i <= n;i++)dis[i] = 1e9;

    priority_queue<Point>Q;
    dis[source] = 0;
    Q.push({source,0});

    while(!Q.empty()){
        int node = Q.top().name;
        Q.pop();
        if(vis[node])continue;
        vis[node] = 1;
        for(auto go : g[node]){
            if(dis[node] + go.second < dis[go.first]){
                dis[go.first] = dis[node] + go.second;
                Q.push({go.first,dis[go.first]});
            }
        }
    }
}
stack<int>st;
int L[N],P[N+5][22];
void dfs(int node)
{
    if(vis[node])return;
    vis[node] = 1;
    for(auto i : g[node]){
        if(dis[i.first] == dis[node] + i.second ){
            par[i.first].insert(node);
            dfs(i.first);
        }
    }
    st.push(node);
}

void add(int from,int to)
{
    G[from].push_back(to);
    P[to][0] = from;
    L[to] = L[from] + 1;
    for(int j = 1;j < 22;j++)P[to][j] = P[P[to][j-1]][j - 1];
}

int query(int p,int q)
{
    if(L[p] < L[q])swap(p,q);

    for(int i = 21;i>=0;i--){
        if(L[P[p][i]] >= L[q])p = P[p][i];
    }
    if(p == q)return p;
    for(int i = 21;i>=0;i--){
        if(P[p][i]!=P[q][i]){
            p = P[p][i]; q = P[q][i];
        }
    }
    return P[p][0];
}
int sub[N];

void DFS(int node)
{
    sub[node] = 1;
    for(int i : G[node]){
        DFS(i);
        sub[node] += sub[i];
    }
}
void AllClear()
{
    MEM(L,0);
    MEM(sub,0);
    MEM(vis,0);
    for(int i = 0;i < N;i++)g[i].clear(),G[i].clear(),par[i].clear();
    for(int i = 0;i < N;i++)for(int j = 0;j<22;j++)P[i][j] = 0;
}
int main()
{
    #ifdef VAMP
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t,cases = 0;
    scanf("%d",&t);

    while(t--){
        AllClear();

        scanf("%d %d",&n,&m);
        for(int i = 0;i < m;i++){
            int u , v , w;
            scanf("%d %d %d",&u,&v,&w);
            g[v].push_back(mk(u,w));
            g[u].push_back(mk(v,w));
        }
        dijkstra(0);
        MEM(vis,0);
        dfs(0);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(par[node].empty())continue;
            int lca = *par[node].begin();
            for(int i : par[node]){
                lca = query(lca,i);
            }
            add(lca,node);
        }
        DFS(0);

        printf("Case %d:\n",++cases);
        scanf("%d",&q);

        while(q--){
            int k;scanf("%d",&k);
            int lca = -1;
            for(int i = 1;i <= k;i++){
                int node;scanf("%d",&node);
                if(sub[node] == 0)continue;
                if(lca == -1)lca = node;
                else lca = query(lca,node);
            }
            if(lca == -1)printf("0\n");
            else printf("%d %d\n",L[lca] + 1,sub[lca]);
        }
    }


    #ifdef VAMP
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}
