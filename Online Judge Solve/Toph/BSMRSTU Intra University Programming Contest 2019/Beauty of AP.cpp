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

const int N = 1000005;
bool stat[N+5];
vector<LL>primes;
void siv()
{
    int sq = sqrt(N);for(int i =4;i<=N;i+=2)stat[i]=1;
    for(int i=3;i<=sq;i+=2)if(!stat[i])for(int j=i*i;j<=N;j+=2*i)stat[j]=1;
    FOR(i,2,N)if(!stat[i])primes.pb(i);
}

vector<LL>op;
LL phi(LL n)
{
    op.clear();
    LL M = n;
    for(int i = 0;i<primes.size() and primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            op.push_back(primes[i]);
            M/=primes[i];
            M*=(primes[i]-1);
            while(n%primes[i] == 0)n/=primes[i];
        }
    }
    if(n>1){
        op.push_back(n);
        M/=n;
        M*=(n-1);
    }
    return M;
}

LL cnt;
void rec(int pos,LL d,int taken,LL n)
{
    if(pos == op.size()){
        if(taken % 2 == 0){
            cnt = cnt + (n/d);
        }else{
            cnt = cnt - (n/d);
        }
        return;
    }
    rec(pos + 1,d * op[pos],taken + 1,n);
    rec(pos + 1,d,taken,n);
}
int main()
{
    FastRead
    siv();
    int t;
    cin >> t;
    while(t--){
        LL a , d , n;
        cin >> a >> d >> n;
        LL howmany = n/d;
        LL p = phi(d);
        n = n % d;
        LL ans = howmany * p;
        cnt = 0;
        rec(0,1,0,n);
        cout << cnt + ans << "\n";
    }
}
