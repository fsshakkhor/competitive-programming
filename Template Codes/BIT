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
const LL MOD = 5000000;
const int N = 100000;
int n,k;
LL bit[51][N+5];
LL update(int id,int idx,int val)
{
    while(idx<=N){
        bit[id][idx]=(bit[id][idx]+val)%MOD;
        idx+=(idx&-idx);
    }
}
LL query(int id,int idx)
{
    LL ret = 0;
    while(idx){
        ret += bit[id][idx];
        idx-=(idx&-idx);
    }
    return ret%MOD;
}
int main()
{
    scanf("%d %d",&n,&k);
    FOR(i,1,n)
    {
        int x;
        scanf("%d",&x);
        for(int r = k;r>1;r--){
            update(r,x+1,query(r-1,x));
        }
        update(1,x+1,1);
    }
    printf("%lld\n",query(k,N));

}
