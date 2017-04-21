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
const LL MOD = 1e9 + 7;
#ifdef MATRIX
const int N=2;

void MatMul(int A[N][N], int B[N][N])
{
    int R[N][N];
    memset(R, 0, sizeof(R));
    REP(i, N) REP(j, N) REP(k, N) R[i][j] = (R[i][j] + A[i][k] * B[k][j]);
    REP(i, N) REP(j, N) B[i][j] = R[i][j];
}


void MatPow(int R[N][N],int M[N][N],int P)
{
    while(P)
    {
        if(P & 1) MatMul(M, R);
        MatMul(M, M);
        P = P >> 1;
    }
}
#endif

bool Check(int N,int pos) { return (bool)(N&(1<<pos)); }
int Set(int N,int pos) { return (N|(1<<pos)); }

int fx[ ] = {-1,0,1,0};
int fy[ ] = {0,1,0,-1};

inline LL BigMod(LL B,LL P,LL M){LL R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
#ifdef FAC
LL fac[200005];void FacGen(){fac[0]=1;FOR(i,1,200000)fac[i]=(fac[i-1]*i)%mod;}
LL COM(LL a,LL b){return ((fac[a]*BigMod((fac[b]*fac[a-b])%mod,mod-2,mod))%mod+mod)%mod;}
#endif

#ifdef egcd
LL egcd(LL a,LL b, LL &x,LL &y)
{
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    LL x1,y1;
    LL d = egcd(b%a,a,x1,y1);
    x = y1 -(b/a)*x1;
    y = x1;
    return d;
}
#endif

#ifdef SIEVE
const int N = 100000;
bool stat[N+5];
vector<int>primes;
void siv()
{
    int sq = sqrt(N);for(int i =4;i<=N;i+=2)stat[i]=1;
    for(int i=3;i<=sq;i+=2)if(!stat[i])for(int j=i*i;j<=N;j+=2*i)stat[j]=1;
    FOR(i,2,N)if(!stat[i])primes.pb(i);
}
#endif
#ifdef PHI
LL phi(LL n)
{
    LL M = n;
    for(int i = 0;i<primes.size() and primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            M/=primes[i];
            M*=(primes[i]-1);
            while(n%primes[i])n/=primes[i];
        }
    }
    if(n>1){
        M/=n;
        M*=(n-1);
    }
    return M;
}
#endif // PHI

#ifdef SEGTREE
LL tree[800005];

void update(LL at,LL L,LL R,LL pos,LL val)
{
    if(pos<L or R<pos)return;

    if(pos==L and pos==R)
    {
        tree[at] = val;
        return;
    }

    LL mid = (L+R)/2;
    update(2*at,L,mid,pos,val);
    update(2*at+1,mid+1,R,pos,val);
    tree[at]=max(tree[2*at],tree[2*at+1]);
}

LL query(LL at,LL L,LL R,LL l,LL r)
{
    if(r<L or R<l)return 0;
    if(l<=L and R<=r)return tree[at];

    LL mid = (L+R)/2;
    LL x = query(2*at,L,mid,l,r);
    LL y = query(2*at+1,mid+1,R,l,r);

    return max(x,y);
}
#endif // SEGTREE


#ifdef LCA
#define mx 100000
LL L[mx];
LL P[mx][22];
LL T[mx];
vector<LL>G[mx];
void dfs(LL from,LL u,LL dep)
{
    T[u]=from;
    L[u]=dep;
    for(LL i=0;i<(LL)G[u].size();i++)
    {
        LL v=G[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

LL lca_query(LL N, LL p, LL q)
  {
      LL tmp, log, i;

      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;

        log=1;
      while(1) {
        LL next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

void lca_init(LL N)
  {
      memset (P,-1,sizeof(P));
      LL i, j;
       for (i = 0; i <= N; i++)
          P[i][0] = T[i];

      for (j = 1; 1 << j <= N; j++)
         for (i = 0; i <= N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }

#endif
