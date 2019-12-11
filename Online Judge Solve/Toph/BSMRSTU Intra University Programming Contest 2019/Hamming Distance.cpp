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


const int N = 1000005;
char s1[N],s2[N];
int n , m;
int dp[26][N];
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%s",s1 + 1);
    scanf("%s",s2 + 1);
    if(m > n){
        printf("0\n");
        return 0;
    }
    for(int i = 1;i <= n;i++){
        int d = s1[i] - 'a';
        for(int j = 0;j < 26;j++){
            if(j == d)dp[j][i] = dp[j][i - 1] + 1;
            else dp[j][i] = dp[j][i - 1];
        }
    }
    LL ans = 0;
    for(int i = 1;i <= m;i++){
        int st = i;
        int rest = m - i;
        int ed = n - rest;
        int d = s2[i] - 'a';
        int mil = dp[d][ed] - dp[d][st - 1];
        int omil = ed - st + 1 - mil;
        ans += omil;
    }
    printf("%lld\n",ans);

}
