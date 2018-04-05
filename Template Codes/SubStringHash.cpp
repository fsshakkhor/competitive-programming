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

const int N = 2000006;
const int M = 44444;
const ULL hs = 3797;

ULL F[N], H[N];
char in[N];
int n;

ULL seg(int x, int y) { // hash value of the segment [x, y]
    return H[y] - F[y - x + 1] * H[x - 1];
}

int main()
{
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs; // keeping the powers pre-calculated
    scanf("%s", in + 1); // 1 indexing
    n = strlen(in + 1);

    H[0] = 0; FOR(i, 1, n + 1) H[i] = H[i - 1] * hs + in[i];

    // now there will be qr queries and we need to check if seg[x, y] == seg[l, r]
    int qr; scanf("%d", &qr) ;
    while(qr--) {
        int x, y, l, r;
        scanf("%d %d %d %d", &x, &y, &l, &r);
        if(seg(x, y) == seg(l, r)) puts("YES");
        else puts("NO");
    }
    return 0;
}
