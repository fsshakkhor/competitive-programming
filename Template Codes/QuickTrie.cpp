#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int N = 200005;
int trie[N * 30][2], sz = 1;
int what_id[N * 30], mark[N * 30];
void add(int x, int id) {
    int cur = 1;
    mark[cur]++;
    for (int i=30; i>=0; i--) {
        bool b = x&(1<<i);
        if (trie[cur][b] == 0) trie[cur][b] = ++sz;
        cur = trie[cur][b];
        mark[cur]++;
    }
    what_id[cur] = id;
}

void del(int x, int id) {
    int cur = 1;
    mark[cur]--;
    for (int i=30; i>=0; i--) {
        bool b = x&(1<<i);
        cur = trie[cur][b];
        mark[cur]--;
    }
    what_id[cur] = 0;
}

int minxor(int x) {
    int cur = 1;
    for (int i=30; i>=0; i--) {
        bool b = x&(1<<i);
        if (trie[cur][b] && mark[trie[cur][b]] > 0)  cur = trie[cur][b];
        else cur = trie[cur][!b];
    }

    return what_id[cur];
}

int pr[N];
int find(int r)
{
    if(pr[r] == r)return r;
    else return pr[r] = find(pr[r]);
}
bool merge(int u,int v)
{
    u = find(u);
    v = find(v);
    if(u == v)return 0;
    pr[v] = u;
    return 1;
}
int n , ara[N];

vector<int>g[N];
struct edge{
    int u , v , cost;
};
int main()
{
    #ifdef VAMP
        clock_t tStart = clock();
        freopen("output.txt", "w", stdout);
        freopen("input.txt", "r", stdin);
    #endif
    FastRead
    cin >> n;
    FOR(i,1,n)cin >> ara[i];
    FOR(i,1,n)pr[i] = i;

    sort(ara + 1, ara + n + 1);
    n = unique(ara + 1, ara + n + 1) - ara - 1;

    int cnt = n;
    LL ans = 0;
    while(cnt > 1){
        for(int i = 1;i <= n;i++){
            g[find(i)].push_back(i);
            add(ara[i],i);
        }
        vector<edge>edges;
        for(int i = 1;i <= n;i++){
            if(g[i].empty())continue;
            for(int j : g[i])del(ara[j],j);
            pair<int,int>now = {2e9,2e9};
            for(int j : g[i]){
                int k = minxor(ara[j]);
                now = min(now,{ara[j]^ara[k],k});
            }
            edges.push_back({i,now.second,now.first});
            for(int j : g[i])add(ara[j],j);
        }
        sort(edges.begin(),edges.end(),[](edge &a,edge &b){
            return a.cost < b.cost;
        });

        for(auto e : edges){
            if(merge(e.u,e.v)){
                cnt--;
                ans += e.cost;
            }
        }
        FOR(i,1,n)g[i].clear();
        FOR(i,1,sz)trie[i][0] = trie[i][1] = mark[i] = 0;
        sz = 1;
    }
    cout << ans << "\n";
    #ifdef VAMP
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}
