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

const int N = 105;

set<int>g[N];
int dp[N][N];
int call(int x,int y)
{
    if(dp[x][y] != -1)return dp[x][y];
    int ret = 0;
    for(int i = x + 1;i <= 100;i++){
        auto it = upper_bound(g[i].begin(),g[i].end(),y);
        if(it != g[i].end() and *it > y){
            ret = max(ret,1 + call(i,*it));
        }
    }
    for(int i = y + 1;i <= 100;i++){
        auto it = upper_bound(g[i].begin(),g[i].end(),x);
        if(it != g[i].end() and *it > x){
            ret = max(ret,1 + call(*it,i));
        }
    }
    return dp[x][y] = ret;
}
int main()
{
    FastRead
    MEM(dp,-1);
    int n;
    cin >> n;
    FOR(i,1,n)
    {
        int x,y;
        cin >> x >> y;
        assert(x >= 1 and y >= 1 and x <= 100 and y <= 100);
        g[x].insert(y);
        g[y].insert(x);
    }
    cout << call(0,0) << "\n";

}
