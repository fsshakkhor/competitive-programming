include<bits/stdc++.h>

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

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);
const int N = 1000005;
bool vis[N][11];
double dp[N][11];

double call(int pos,int k)
{
    if(pos <= 0)return 0;
    if(vis[pos][k])return dp[pos][k];
    vis[pos][k] = 1;
    double ret = k;
    for(int i = 1;i < k;i++){
        ret = ret + call(pos - i,k);
    }
    ret = ret / (k - 1);
    return dp[pos][k] = ret;
}
int main()
{
    FastRead
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        cout << fixed << setprecision(9) << call(n,k) << "\n";
    }

}
