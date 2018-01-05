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
int ara[1 << N];
int lim = (1 << N) - 1;

int main()
{
   FastRead
   cin >> n;
   FOR(i,1,n){
      cin >> ara[i];
      F[ara[i]] = ara[i];
   }
   for(int mask = 1;mask < (1 << N);mask++){

      for(int i = 0;i < N;i++){
         if(mask & (1 << i) and F[mask ^ (1 << i)]){
            F[mask] = F[mask ^ (1 << i)];
         }
      }
   }
   FOR(i,1,n)
   {
      int inv = lim ^ ara[i];
      int ans = F[inv];
      if(ans == 0)ans = -1;
      cout << ans << " ";
   }


}

