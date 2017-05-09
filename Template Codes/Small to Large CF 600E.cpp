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
const int N = 100005;
vector<int>G[N];
map<int,int>mp[N];

int n,color[N],id[N],maxcount[N];
LL answer[N],cnt[N];

void update(int x,int counter,int color)
{
    if(counter>maxcount[x])maxcount[x]=counter,cnt[x]=0;
    if(counter==maxcount[x])cnt[x]+=color;
}
void merge(int &x,int y)
{
    if(mp[x].size()<mp[y].size())swap(x,y);
    for(auto it = mp[y].begin();it!=mp[y].end();it++){
        mp[x][it->first]+=it->second;
        update(x,mp[x][it->first],it->first);
    }
}
void dfs(int node,int pre)
{
    id[node]=node;
    mp[node][color[node]]=1;
    cnt[node] = color[node];
    maxcount[node]=1;

    for(int i : G[node]){
        if(i==pre)continue;
        dfs(i,node);
        merge(id[node],id[i]);
    }
    answer[node] = cnt[id[node]];
}
int main()
{
    scanf("%d",&n);
    FOR(i,1,n)scanf("%d",&color[i]);

    FOR(i,1,n-1){
        int a,b;
        scanf("%d %d",&a,&b);
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1,0);
    FOR(i,1,n)printf("%lld ",answer[i]);
}
