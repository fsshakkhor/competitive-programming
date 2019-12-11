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

inline LL BigMod(LL B,LL P,LL M){LL R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}

const LL MOD = 1e9 + 7;

int main()
{
    FastRead
//    cout << (BigMod(2,MOD-2,MOD) * 3) % MOD << "\n";
    int t;
    cin >> t;
    while(t--){
        LL n;
        cin >> n;
        LL num = BigMod(2,n,MOD);num = (num + MOD) % MOD;
        LL sum = (num * (num - 1)) % MOD;
        sum = (sum * BigMod(2,MOD-2,MOD)) % MOD;
        LL down = BigMod(num,MOD-2,MOD);
        sum = (sum * down) % MOD;
        sum = (sum + MOD) % MOD;

        cout << sum << "\n";
    }
}
