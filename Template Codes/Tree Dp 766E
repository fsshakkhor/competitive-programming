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
bool Check(int N,int pos) { return (bool)(N&(1<<pos)); }
int Set(int N,int pos) { return (N|(1<<pos)); }

vector<int>G[100005];
int dp[100005][24][2];
int n;
int ara[100005];
LL mul[24];
int nob = 23;
void dfs(int u,int pre)
{
   for(int v : G[u]){
      if(v==pre)continue;
      dfs(v,u);

      for(int i = 0;i < nob;i++){
         int bit = Check(ara[u],i);

         mul[i] += dp[u][i][0] * dp[v][i][1];
         mul[i] += dp[u][i][1] * dp[v][i][0];
//         cout << "from to " <<  u << " " << v << endl;
//         cout << dp[u][i][0] << " " << dp[v][i][1] << " ";
//         cout << dp[u][i][1] << " " << dp[v][i][0] << "\n";
         if(bit == 0){
            dp[u][i][0] += dp[v][i][0];
            dp[u][i][1] += dp[v][i][1];
         }else{
            dp[u][i][0] += dp[v][i][1];
            dp[u][i][1] += dp[v][i][0];
         }
      }
   }
   for(int i = 0;i < nob;i++){
         if(Check(ara[u],i))dp[u][i][1] += 1;
         else dp[u][i][0] += 1;
   }
   for(int i = 0;i < nob;i++){
      mul[i] += dp[u][i][1];
   }

}
int main()
{
   scanf("%d",&n);
   for(int i = 1;i<=n;i++)scanf("%d",&ara[i]);
   FOR(i,1,n-1)
   {
      int a,b;
      scanf("%d %d",&a,&b);
      G[a].pb(b);
      G[b].pb(a);
   }
   dfs(1,0);
   LL ans = 0;
   for(int i = 0;i<nob;i++){
      ans = ans + (1LL << i) * mul[i];
   }
   printf("%lld\n",ans);


}
