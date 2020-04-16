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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using orderset = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; // find_by_order, order_of_key

const int N = 100005;

int n , q;
vector<int>g[N];
int st[N],ed[N],timer = 0;
int ara[N],newara[N];
void dfs(int node,int pre)
{
    st[node] = ++timer;
    newara[timer] = ara[node];

    for(int i : g[node]){
        if(i == pre)continue;
        dfs(i,node);
    }
    ed[node] = timer;
}

orderset<pii>Tree[4 * N];
void update(int node,int L,int R,int pos,int val)
{
    if(pos < L or pos > R)return;
    Tree[node].insert(mk(val,pos));
    if(L == R)return;
    int mid = (L + R)/2;
    update(2 * node,L,mid,pos,val);
    update(2 * node + 1,mid + 1,R,pos,val);
}
void removes(int node,int L,int R,int pos,int val)
{
    if(pos < L or pos > R)return;
//    debug(L,R,pos,val);

//    cout << "before\n";
//    for(int i : Tree[node])cout << i << " ";cout << "\n";

    Tree[node].erase(mk(val,pos));

//    cout << "after\n";
//    for(int i : Tree[node])cout << i << " ";cout << "\n";

    if(L == R)return;
    int mid = (L + R)/2;
    removes(2 * node,L,mid,pos,val);
    removes(2 * node + 1,mid + 1,R,pos,val);
}
inline int query(int node,int L,int R,int l,int r,int v)
{
    if(r < L or R < l)return 0;
    if(Tree[node].empty())return 0;
    if(l <= L and R <= r){
//        debug(L,R,l,r,v);
        int cnt = Tree[node].size() - Tree[node].order_of_key(mk(v + 1,0));
        return cnt;
    }
    int mid = (L + R)/2;
    int x = query(2 * node,L,mid,l,r,v);
    int y = query(2 * node + 1,mid + 1,R,l,r,v);
    return x + y;
}
int main()
{
    #ifdef VAMP
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> q;
    for(int i = 1;i <= n;i++)cin >> ara[i];
    for(int i = 1;i < n;i++){
        int a , b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++){
        update(1,1,n,i,newara[i]);

    }
    while(q--){
        int tp;
        cin >> tp;
        if(tp == 1){
            int u , val;
            cin >> u >> val;
            removes(1,1,n,st[u],newara[st[u]]);
            newara[st[u]] = val;
            update(1,1,n,st[u],newara[st[u]]);
        }else{
            int u;
            cin >> u;
            int l = st[u] , r = ed[u];
            int ans = query(1,1,n,l,r,newara[l]);
            cout << ans << "\n";
        }
    }
    #ifdef VAMP
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}
