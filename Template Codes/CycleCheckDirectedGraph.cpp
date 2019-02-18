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

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,b) for(int i=0;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
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
const int N = 300001;
vector<int>G[N];
char str[N];
int ara[N],dp[N];
int vis[N],mark[N];
int n,m;

stack<int>st;
void topological(int node)
{
    if(vis[node])return;
    vis[node] = 1;
    for(int i : G[node]){
        topological(i);
    }
    st.push(node);
}
void dfs(int node)
{
    vis[node] = 1;
    for(int i : G[node]){
        if(vis[i] == 2)continue;
        if(vis[i] == 1){
            cout << -1 << "\n";
            exit(0);
        }
        dfs(i);
    }
    vis[node] = 2 ;
}
int call(int node)
{
    if(dp[node] != -1)return dp[node];
    int ret = ara[node];
    for(int i : G[node]){
        ret = max(ret,ara[node] + call(i));
    }
    return dp[node] = ret;
}
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%s",str);
    for(int i = 1;i <= m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        G[a].pb(b);
    }
    for(int i = 1;i <= n;i++)topological(i);
    MEM(vis,0);
    for(int i = 1;i <= n;i++){
        if(vis[i] == 0)dfs(i);
    }
    int ans = 0;
    for(int ch = 0;ch < 26;ch++){
        MEM(ara,0);MEM(dp,-1);
        for(int i = 0;i < n;i++){
            if(str[i] - 'a' == ch){
                ara[i + 1] = 1;
            }
        }
//        for(int i = 1;i <= n;i++)cout << ara[i] << " ";cout << endl;
        for(int i = 1;i <= n;i++)ans = max(ans,call(i));
    }
    printf("%d\n",ans);
}
