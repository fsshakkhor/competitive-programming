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

const int N = 102;
int n , k;
vector<pii>g[N];
int sibling[N],child[N],ara[N];

void build(int node,int pre)
{
    int last = -1;
    for(pii i : g[node]){
        if(i.first == pre)continue;
        if(last != -1)sibling[last] = i.first;
        if(child[node] == 0)child[node] = i.first;
        last = i.first;
        ara[i.first] = i.second;
        build(i.first,node);
    }
}
int dp[N][N];
int call(int node,int res)
{
    if(res < 0)return 1e9;
    if(node == 0)return 0;
    if(dp[node][res] != -1)return dp[node][res];
    int ret = 1e9;

    //new child
    ret = min(ret,1 + call(child[node],k) + call(sibling[node],res));

    for(int i = ara[node];i <= res;i++){
        ret = min(ret,call(child[node],i - ara[node]) + call(sibling[node],res - i));
    }
    return dp[node][res] = ret;
}
int main()
{
    int t,cases = 0;
    scanf("%d",&t);
    while(t--){
        for(int i = 0;i < N;i++)g[i].clear();
        MEM(sibling,0);
        MEM(child,0);
        MEM(dp,-1);
        scanf("%d %d",&n,&k);

        for(int i = 1;i < n;i++){
            int u , v , w;
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(mk(v,w));
            g[v].push_back(mk(u,w));
        }
        build(1,0);
        printf("Case %d: %d\n",++cases,1 + call(1,k));

    }
}
/*
5
5 2
2 1 1
2 5 1
1 3 1
1 4 1
6 5
1 5 2
3 4 1
1 4 1
4 2 2
3 6 1
1 100
5 1
1 2 100
1 3 1
1 4 2
1 5 1
5 3
1 2 2
1 3 1
2 4 1
2 5 1

1
6 5
1 2 1
1 3 1
1 4 1
4 5 1
4 6 1

*/
