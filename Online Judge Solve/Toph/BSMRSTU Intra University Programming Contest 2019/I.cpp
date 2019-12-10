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

const int N = 100005;
const int M = 44444;
const ULL hs = 3797;
ULL F[N], L[N], R[N];
char in[N];
int n;
ULL seg(int x, int y) {
    return (L[y] - L[x-1]) * F[n - y];
}
ULL seg2(int x, int y) {
    return (R[x] - R[y + 1]) * F[x - 1];
}
void solve()
{
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs;
    scanf("%s", in + 1);
    n = strlen(in + 1);
    if(n == 1){
        printf("%s %s\n",in + 1,in + 1);
        return;
    }
    FOR(i, 1, n) L[i] = L[i - 1] + in[i] * F[i - 1];
    ROF(i, n, 1) R[i] = R[i + 1] + in[i] * F[n - i];


    int lo = 2  , hi = n - 1, mid,ans = n;

    for(int i = lo;i <= hi;i++){
        if(seg(i,n) == seg2(i,n)){
            ans = min(ans,i);
        }
    }
    printf("%s ",in + 1);
    for(int i = ans - 1;i >= 1;i--)printf("%c",in[i]);
    printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
