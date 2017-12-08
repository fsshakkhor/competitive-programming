#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             1000000000
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

const int N = 100005;

vector<int>roots,G[N];
map<string,int>mp;
vector<pii>que[N];

int n,m;
int ara[N],L[N],answer[N];

void dfs(int node,int deep)
{
    L[node] = deep;
    for(int i : G[node]){
        dfs(i,deep+1);
    }
}

void dsu(int node,map<int,set<int>> &g)
{

    for(int i : G[node]){
        map<int,set<int>>s;
        dsu(i,s);
        if(s.size() > g.size())swap(g,s);

        for(auto it : s){
            g[it.ff].insert(it.ss.begin(),it.ss.end());
        }
    }
    g[L[node]].insert(ara[node]);

    for(pii i: que[node]){
        answer[i.ss] = g[i.ff].size();
    }
}
int main()
{
    FastRead
    cin >> n;
    FOR(i,1,n)
    {
        string s; int p;
        cin >> s >> p;
        static int id = 0;
        if(mp[s] == 0)mp[s] = ++id;

        ara[i] = mp[s];

        if(p == 0)roots.push_back(i);
        else G[p].push_back(i);
    }
    for(int i : roots)dfs(i,0);

    cin >> m;
    FOR(i,1,m)
    {
        int v,k;
        cin >> v >> k;
        int lev = L[v] + k;
        que[v].push_back(mk(lev,i));
    }
    map<int,set<int>>g;
    for(int i : roots){
        dsu(i,g);
        g.clear();
    }
    FOR(i,1,m)cout << answer[i] << "\n";
}
