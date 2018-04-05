#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             5e13
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

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

const int N = 100000;

int L[N+5];
int Pr[N+5];
int P[N+5][22];
int child[N + 5];
vector<int>G[N];

int dfs(int node,int pre,int dep)
{
    Pr[node] = pre;
    L[node] = dep;
    int ret = 1;
    for(int i : G[node]){
        if(i==pre)continue;
        ret += dfs(i,node,dep+1);
    }
    return child[node] = ret;
}
void init()
{
    for(int i = 0;i<=N;i++)for(int j = 0;j<22;j++)P[i][j] = 1;
    FOR(i,1,N)P[i][0] = Pr[i];

    for(int j = 1;(1 << j) <= N;j++){
        for(int i = 0;i<=N;i++){
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
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
    return Pr[p];
}
