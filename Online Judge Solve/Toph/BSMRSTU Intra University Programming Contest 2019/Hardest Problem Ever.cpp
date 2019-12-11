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

const LL LIMIT = 1e18 + 10;
LL a , b , c, l , r;
int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> l >> r;
        r = r - c;
        l = l - c;
        LL lo = 1, hi = 1e9, mid,ans1 = 0;

        while(lo <= hi){
            mid = (lo + hi)/2;
            LL g = mid * mid * a + b * mid;
            if(g <= r){
                ans1 = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        lo = 1, hi = 1e9;
        LL ans2 = 0;
        while(lo <= hi){
            mid = (lo + hi)/2;
            LL g = mid * mid * a + b * mid;
//            cout << g << " " << l << "\n";
            if(g < l){
                ans2 = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        cout << ans1 - ans2 << "\n";
//        cout << ans1 << " " << ans2 << "\n";

    }
}
