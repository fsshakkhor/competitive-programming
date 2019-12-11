#include<bits/stdc++.h>

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

const int N = 100005;
LL n , ara[N];
int main()
{
    LL t,cases = 0;
    scanf("%lld",&t);

    while(t--){
        scanf("%lld",&n);

        priority_queue<pll>Q;
        FOR(i,1,n){
            scanf("%lld",&ara[i]);
            Q.push(mk(ara[i],i));
        }
        LL q;
        scanf("%lld",&q);

        while(q--){
            LL m;
            scanf("%lld",&m);

            while(1){
                pll P = Q.top();
                if(P.first < m)break;
                Q.pop();
                Q.push(mk(P.first % m,P.second));
            }
        }
        while(!Q.empty()){
            pll P = Q.top();
            ara[P.second] = P.first;
            Q.pop();
        }
        printf("Case %lld:\n",++cases);
        for(int i = 1;i <= n;i++){
            if(i > 1)printf(" ");
            printf("%lld",ara[i]);
        }
        printf("\n");
    }

}
