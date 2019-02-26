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

const int MAXP = 9765625 + 1;
const long long MOD = 10000000000LL;

namespace crt{
    LL extended_gcd(LL a, LL b, LL& x, LL& y){
        if (!b){
            y = 0, x = 1;
            return a;
        }
        LL g = extended_gcd(b, a % b, y, x);
        y -= ((a / b) * x);
        return g;
    }

    LL mod_inverse(LL a, LL m){
        LL x, y;
        extended_gcd(a, m, x, y);
        return (x + m) % m;
    }

    LL chinese_remainder(vector <LL> ar, vector <LL> mods){
        LL x, y, res = 0, M = 1;
        for (int i = 0; i < ar.size(); i++) M *= mods[i];
        for (int i = 0; i < ar.size(); i++){
            x = M / mods[i], y = mod_inverse(x, mods[i]);
            res = (res + (((x * ar[i]) % M) * y)) % M;
        }
        return res;
    }
}

namespace bin{
    LL mod = 0, dp[MAXP];

    LL trailing(LL x, LL p){
        LL res = 0;
        while (x){
            x /= p;
            res += x;
        }
        return res;
    }

    LL expo(LL a, LL b, LL m){
        LL res = 1;

        while (b){
            if (b & 1) res = res * a % m;
            a = a * a % m, b >>= 1;
        }
        return res;
    }

    LL factorial(LL x, LL p){
        LL res = expo(dp[mod - 1], x / mod, mod);
        if (x >= p) res = res * factorial(x / p, p) % mod;
        return res * dp[x % mod] % mod;
    }

    LL binomial(LL n, LL k, LL p, LL q){
        if (k > n || k < 0) return 0;
        if (n == k || k == 0) return 1;

        int i, j;
        for (i = 0, mod = 1; i < q; i++) mod *= p;
        LL t = trailing(n, p) - trailing(k, p) - trailing(n - k, p);
        if (t >= q) return 0;

        assert(mod < MAXP);
        for (dp[0] = 1, i = 1; i < mod; i++){
            dp[i] = (LL)dp[i - 1] * ((i % p) ? i : 1) % mod;
        }

        LL res = factorial(n, p) * expo(factorial(k, p) * factorial(n - k, p) % mod, (mod / p) * (p - 1) - 1, mod) % mod;
        for (i = 0; i < t; i++) res = res * p % mod;
        return res;
    }

    LL binomial(LL n, LL k, LL m){
        if (k > n || m == 1 || k < 0) return 0;
        if (n == k || k == 0) return 1;

        vector <pair<int, int>> factors;
        for (LL i = 2; i * i <= m; i++){
            int c = 0;
            while (m % i == 0){
                c++;
                m /= i;
            }
            if (c) factors.push_back(make_pair(i, c));
        }
        if (m > 1) factors.push_back(make_pair(m, 1));

        vector <LL> ar, mods;
        for (int i = 0; i < factors.size(); i++){
            LL x = 1;
            for (int j = 0; j < factors[i].second; j++) x *= factors[i].first;
            mods.push_back(x), ar.push_back(binomial(n, k, factors[i].first, factors[i].second));
        }
//        for(int j : ar)cout << j << " ";cout << endl;
//        for(int j : mods)cout << j << " ";cout << endl;
        return crt::chinese_remainder(ar, mods);
    }
}

bool ok(LL n,LL k)
{
    if(k < 0 or k > n)return false;
    k = min(k, n - k);

    long double x = 1;
    LL u = n, v = 1;

    for(LL i = 0;i < k;i++){
        x = x * u;
        x = x / v;
        if(x >= 1.0 * MOD)return false;
        u--;v++;
    }
    return true;
}
int main()
{
//    fRead("combi.in");
//    fWrite("combi.out");
    LL n , k;
    cin >> n >> k;
    k = min(k,n - k);

    if(ok(n,k))printf("%lld\n",bin::binomial(n,k,MOD));
    else printf("...%010lld\n",bin::binomial(n,k,MOD));

}
