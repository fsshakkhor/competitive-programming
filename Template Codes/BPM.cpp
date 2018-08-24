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
const int N = 1505;
int matchR[N],store[N];
bool vis[N];
vector<int>G[N];

bool dfs(int u)
{
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(vis[v])continue;
        vis[v] = 1;
        if(matchR[v] == 0 || dfs(matchR[v])){
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
int main()
{
    FastRead
    int m,n,k;
    cin >> m >> n >> k;
    for(int i = 0;i < k;i++){
        int a,b;
        cin >> a >> b;
        G[a].pb(b);
    }
    int Ans = 0, Extra = 0;
    for(int i = 1;i <= m;i++){
        MEM(vis,0);
        if(dfs(i))Ans++;
    }
    for(int i = 1;i <= n;i++)store[i] = matchR[i];

    for(int i = 1;i <= m;i++){
        int temp = 0;
        for(int j = 1;j <= n;j++)matchR[j] = store[j];
        MEM(vis,0);
        temp += dfs(i);

        MEM(vis,0);
        temp += dfs(i);

        Extra = max(Extra,temp);
        if(Extra == 2)break;
    }
    cout << Ans + Extra << "\n";

}
