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

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,b) for(int i=0;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
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
int ara[N],n,q,bara[N];
int table[N][18];
int save[N];
void sparsTable() {
    for(int i = 0; i < n; i++) table[i][0] = ara[i];
    for(int j = 1; save[j] <= n; j++) for(int i = 0; i + save[j] <= n; i++) table[i][j] = max( table[i][j - 1], table[i + (save[j-1])][j - 1] );
}
int LOG[N];
int query(int x, int y) {
    if(x == y)return ara[x];
    if(x > y) swap(x, y);
    int k = LOG[y - x];
    return max( table[x][k], table[y - save[k] + 1][k] );
}

int main()
{
    for(int i = 0;i < N;i++)LOG[i] = log2(i);
    for(int i = 0;i < 20;i++)save[i] = 1 << i;
    int t,cases = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&q);
        for(int i = 0;i < n;i++)scanf("%d",&ara[i]);
        sparsTable();
        printf("Case #%d:\n",++cases);
        while(q--){
            int l ,r;
            scanf("%d %d",&l,&r);l--;r--;
            printf("%d\n",query(l,r));
        }

    }
}
