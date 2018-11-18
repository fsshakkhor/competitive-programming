//https://www.codechef.com/problems/CHEFAOR

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
const int N = 5005;
int n,k,ara[N],A[N][N];
LL dp[N][N];

inline void solve(int L,int R,int x,int y,int id)
{
    if(L > R)return;
    int mid = (L + R)/2;
    pair<LL,int> best = mk(-1,-1);
    for(int i = x;i <= min(y,mid);i++){
        best = max(best,{dp[id-1][i-1] + A[i][mid],i});
    }
    dp[id][mid] = best.first;
    solve(L,mid-1,x,best.ss,id);
    solve(mid+1,R,best.ss,y,id);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n,&k);
        for(int i = 1;i <= n;i++)scanf("%d",&ara[i]);

        for(int i = 1;i <= n;i++){
            A[i][i] = ara[i];
            for(int j = i + 1;j <= n;j++){
                A[i][j] = A[i][j-1] | ara[j];
            }
        }
        for(int i = 1;i <= n;i++){
            dp[0][i] = A[1][i];
        }
        for(int i = 1;i < k;i++){
            solve(1,n,1,n,i);
        }
        printf("%lld\n",dp[k-1][n]);
    }
}
/*
1
4 2
1 2 3 4
*/
