//https://www.spoj.com/problems/NKLEAVES/en/
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
#define eps             1e-9

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

using namespace std;
const int N = 100005;
int n,k,ara[N];
LL F[N],S[N],dp[11][N];

LL get(int l,int r)
{
    LL s = F[r] - F[l-1] - (S[r] - S[l-1]) * l;
    return s;
}
void solve(int l,int r,int x,int y,int id)
{
    if(l > r)return;
    int mid = (l + r)/2;
    pair<LL,int>worst = mk(1e18,-1);
    for(int i = x;i <= min(y,mid);i++){
        worst = min(worst,mk(dp[id-1][i-1] + get(i,mid) ,i));
    }
    dp[id][mid] = worst.first;
    solve(l,mid-1,x,worst.second,id);
    solve(mid+1,r,worst.second,y,id);
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i = 1;i <= n;i++)scanf("%d",&ara[i]);

    for(int i = 1;i <= n;i++)F[i] = F[i-1] + (LL)ara[i] * (LL)i;
    for(int i = 1;i <= n;i++)S[i] = S[i-1] + ara[i];

    for(int i = 1;i <= n;i++)dp[0][i] = get(1,i);
    for(int i = 1;i < k;i++){
        solve(1,n,1,n,i);
    }
    printf("%lld\n",dp[k-1][n]);
//    for(int i = 0;i < k;i++){
//        for(int j = 1;j <= n;j++)cout << dp[i][j] << " ";
//        cout << "\n";
//    }
}
