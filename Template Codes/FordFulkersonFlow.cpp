#include<bits/stdc++.h>
 
using namespace std;
 
#define fRead(x)  freopen(x,"r",stdin)
#define fWrite(x) freopen (x,"w",stdout)
 
#define LL long long
#define ULL unsigned long long
#define ff first
#define ss second
#define pb push_back
#define INF 2e16
#define PI acos(-1.0)
#define mk make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>
 
 
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,b) for(int i=0;i<b;i++)
#define MEM(a,x) memset(a,x,sizeof(a))
#define ABS(x) ((x)<0?-(x):(x))
 
#define scanI(a) scanf("%d",&a)
#define scanI2(a,b) scanI(a) , scanI(b)
#define scanI3(a,b,c) scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)
 
#define scanL(a) scanf("%I64d",&a)
#define scanL2(a,b) scanL(a) , scanL(b)
#define scanL3(a,b,c) scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)
 
#define SORT(v) sort(v.begin(),v.end())
#define REV(v) reverse(v.begin(),v.end())
 
 
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);
const int N = 100;
int cost[N+5][N+5];
int n,s,t,c;
int pr[N+5];
bool vis[N+5];
 
int bfs()
{
    MEM(vis,0);
    queue<int>Q;
    Q.push(s);
    vis[s]=1;
    pr[s]=-1;
    while(not Q.empty()){
        int node = Q.front();
        Q.pop();
        for(int i = 1;i<=n;i++){
            if(vis[i]==0 and cost[node][i]>0){
                Q.push(i);
                pr[i]=node;
                vis[i]=1;
            }
        }
    }
    return vis[t];
 
}
int main()
{
    int T,cases=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
 
        MEM(cost,0);MEM(pr,0);
 
        scanf("%d %d %d",&s,&t,&c);
        while(c--){
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            cost[a][b]+=w;
            cost[b][a]+=w;
        }
        int flow = 0;
 
        while(bfs()){
            int path = 1e9;
            for(int v = t;v!=s;v= pr[v]){
                int u = pr[v];
                path = min(path,cost[u][v]);
            }
            for(int v = t;v!=s;v=pr[v]){
                int u = pr[v];
                cost[u][v]-=path;
                cost[v][u]+=path;
            }
            flow+=path;
        }
        printf("Case %d: %d\n",++cases,flow);
    }
 
}
