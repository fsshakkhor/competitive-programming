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

const int N = 1000005;
LL Mul(LL a, LL b, LL m)
{
	LL ret=0, c=a;
	while(b)
	{
		if(b&1) ret=(ret+c)%m;
		b>>=1; c=(c+c)%m;
	}
	return ret;
}
LL bigmod(LL a, LL n, LL m)
{
	LL ret=1, c=a;
	while(n)
	{
		if(n&1) ret=Mul(ret, c, m);
		n>>=1; c=Mul(c, c, m);
	}
	return ret;
}
bool isPrime(long long n) {
    if (n == 2) return 1;
    if (n%2 == 0) return 0;
    long long d = n-1;
    while(d%2 == 0) d >>= 1;
    int test[] = {2,3,5,7,11,13,17,19,23};
    for(int i = 0; i < 9; i++) {
        long long x = test[i]%(n-2), temp = d;
        if (x < 2) x += 2;
        long long a = bigmod(x, d, n);
        while(temp != n-1 && a != 1 && a != n-1) {
            a = Mul(a, a, n);
            temp <<= 1;
        }
        if (a != n-1 && (temp&1) == 0) return 0;
    }
    return 1;
}

long long pollard_rho(long long n, long long c) {
    long long x = 2, y = 2, i = 1, k = 2, d;
    while(true) {
        x = (Mul(x, x, n) + c);
        if (x >= n) x -= n;
        d = __gcd(abs(x-y),n);
        if (d > 1) return d;
        if (++i == k) {
            y = x, k <<= 1;
        }
    }
    return n;
}
bool stat[N];
vector<LL>primes;

void siv()
{
    for(int i = 4;i < N;i += 2)stat[i] = 1;
    int sq = sqrt(N);
    for(int i = 3;i <= sq;i += 2){
        if(stat[i])continue;
        for(int j = i * i;j < N;j += 2 * i)stat[j] = 1;
    }
    for(int i = 2;i < N;i++)if(stat[i] == 0)primes.push_back(i);
}
void llfactorize(long long n, vector<long long> &f) {
    if (n == 1) return;
    if (n < 1e9) {
        for(int i = 0; primes[i]* primes[i] <= n; i++) {
            while(n%primes[i] == 0) {
                f.push_back(primes[i]);
                n /= primes[i];
            }
        }
        if (n != 1) f.push_back(n);
        return;
    }
    if (isPrime(n)) {
        f.push_back(n);
        return;
    }
    long long d = n;
    for(int i = 2; d == n; i++){
        d = pollard_rho(n, i);
    }
    llfactorize(d, f);
    llfactorize(n/d, f);
}
void factorize(long long n, vector<pair<long long,long long>> &ans) {
    vector<long long> v;
    llfactorize(n, v);
    if(v.size() == 0)return;
    sort(v.begin(), v.end());
    long long a = v[0], b = 1;
    for(int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1] ) b++;
        else {
            ans.push_back({a,b});
            a = v[i];
            b = 1;
        }
    }
    ans.push_back({a,b});
}

LL n , ara[N], x;
int dp[1 << 15];

int main()
{
    siv();
    int t,cases = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&x);
        FOR(i,1,n)scanf("%lld",&ara[i]);
        unordered_set<LL>st;
        for(int i = 1;i <= n;i++){
            if(x % ara[i] == 0)st.insert(ara[i]);
        }
        vector<LL>vec(st.begin(),st.end());

        vector<pll>fac;
        factorize(x,fac);
        vector<LL>FAC;
        for(int i = 0;i < fac.size();i++){
            LL ret = 1;
            for(int j = 1;j <= fac[i].second;j++){
                ret = ret * fac[i].first;
            }
            FAC.push_back(ret);
        }

        int lim = (1 << FAC.size());
        for(int i = 0;i < lim;i++)dp[i] =  1e9;


        for(int i = 0;i < vec.size();i++){
            int mask = 0;
            for(int j = 0;j < FAC.size();j++){
                if(vec[i] % FAC[j] == 0){
                    mask = mask | (1 << j);
                }
            }
            dp[mask] = 1;
        }
        for(int mask = 0;mask < lim;mask++){
            for(int newmask = mask;newmask > 0;newmask = (newmask - 1) & mask){
                dp[newmask] = min(dp[mask],dp[newmask]);
            }
        }
        for(int mask = 0;mask < lim;mask++){
            for(int newmask = mask;newmask > 0;newmask = (newmask - 1) & mask){
                int other = newmask ^ mask;
                dp[mask] = min(dp[mask],dp[newmask] + dp[other]);
            }
        }
        if(dp[lim - 1]> 15)dp[lim - 1] = -1;
        cout << "Case " << ++cases << ": " << dp[lim - 1] << "\n";


    }


}
