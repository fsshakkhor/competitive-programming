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

int L[N+5];
int Pr[N+5];
int P[N+5][22];
int child[N + 5];
LL dis[N + 5];
vector<pii>G[N];

void dfs(int node,int pre,int dep,LL D)
{
    Pr[node] = pre;
    L[node] = dep;
    dis[node] = D;

    int ret = 1;
    for(auto i : G[node]){
        if(i.first==pre)continue;
        dfs(i.first,node,dep + 1,D + i.second);
    }
}
void init()
{
    for(int i = 0;i< N;i++)for(int j = 0;j<18;j++)P[i][j] = 1;
    FOR(i,1,N - 1)P[i][0] = Pr[i];

    for(int j = 1;(1 << j) < N;j++){
        for(int i = 0;i< N;i++){
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int query(int p,int q)
{
    if(L[p] < L[q])swap(p,q);

    for(int i = 17;i>=0;i--){
        if(L[P[p][i]] >= L[q])p = P[p][i];
    }
    if(p == q)return p;
    for(int i = 17;i>=0;i--){
        if(P[p][i]!=P[q][i]){
            p = P[p][i]; q = P[q][i];
        }
    }
    return Pr[p];
}

LL Dist(int x,int y)
{
    int p = query(x,y);
    LL D = dis[x] + dis[y] - 2 * dis[p];
    return D;
}
int ara[N];
int main()
{
    #ifdef VAMP
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n , q;
    scanf("%d %d",&n,&q);
    for(int i = 1;i < n;i++){
        int a , b, c;
        scanf("%d %d %d",&a,&b,&c);
        G[a].pb(mk(b,c));
        G[b].pb(mk(a,c));
    }
    dfs(1,1,0,0);
    init();

    while(q--){
        int k;
        scanf("%d",&k);
        for(int i = 1;i <= k;i++)scanf("%d",&ara[i]);

        vector<int>cur;
        cur.push_back(ara[1]);
        cur.push_back(ara[2]);
        LL pre = Dist(cur[0],cur[1]);

        for(int i = 3;i <= k;i++){
            LL d1 = Dist(cur[0],ara[i]);
            LL d2 = Dist(cur[1],ara[i]);
            LL d3 = pre;

            LL D = max3(d1,d2,d3);
            if(D == d1){
                cur.pop_back();
                cur.push_back(ara[i]);
            }else if(D == d2){
                cur.erase(cur.begin());
                cur.push_back(ara[i]);
            }
            pre = D;
        }
        LL ans = pre;
        printf("%lld\n",ans);
    }
    #ifdef VAMP
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}
