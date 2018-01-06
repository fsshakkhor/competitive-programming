//Codeforces 165E

#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             5e13
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

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
const int N = 22;
int F[1 << N],n;
int ara[1000006];
int lim = (1 << N) - 1;

int main()
{
   MEM(F,-1);
   int n;
   scanf("%d",&n);
   FOR(i,1,n)scanf("%d",&ara[i]) , F[ara[i]] = ara[i];
   LL ans = 0;

   for(int i = 0;i < N; ++i) {
      for(int mask = 0; mask < (1<<N); ++mask){
            if(mask & (1<<i) and F[mask^(1<<i)] > 0){
               F[mask] = F[mask^(1<<i)];
            }
         }
   }
   for(int i = 1;i<=n;i++){
      printf("%d ",F[ara[i]^lim]);
   }
}



