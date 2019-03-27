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
const int N = 500005;
LL ara[N],n,k = 20,bara[N];
LL table[N][21];

void sparsTable() {
    for(int i = 0; i < n; i++) table[i][0] = ara[i];
    for(int j = 1; (1 << j) <= n; j++) for(int i = 0; i + (1 << j) <= n; i++) table[i][j] = __gcd( table[i][j - 1], table[i + (1 << (j - 1))][j - 1] );
}
LL query(int x, int y) {
    if(x == y)return ara[x];
    if(x > y) swap(x, y);
    LL k = log2(y - x);
    return __gcd( table[x][k], table[y - (1 << k) + 1][k] );
}
int main()
{
    scanf("%lld",&n);
    for(LL i = 0;i < n;i++)scanf("%lld",&ara[i]);
    int index = 1;
    bara[0] = ara[0];
    for(int i = 1;i < n;i++){
        if(ara[i] == ara[i - 1])continue;
        bara[index++] = ara[i];
    }
    n = index;
    for(int i = 0;i < n;i++)ara[i] = bara[i];

    sparsTable();

    LL l,r;


    unordered_set<LL>st;
    bool ok = 0;
    for(int i = 0;i < n;i++){
        index = i;
        while(index < n){
            int lo = index , hi = n - 1,mid,ans;
            LL g = query(i,index);
            if(g == 1){
                ok = 1;
                break;
            }
            while(lo <= hi){
                mid = (lo + hi)/2;
                if(g == query(i,mid)){
                    ans = mid;
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            }
            st.insert(g);
            index = ans + 1;
        }
    }
    if(ok)st.insert(1);
    printf("%d\n",(int)st.size());
}
