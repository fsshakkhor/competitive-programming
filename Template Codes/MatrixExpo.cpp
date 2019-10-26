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

const LL MOD = 1000000007;
const int N = 102;
const int iter = 25;
LL mat[iter][N][N];

void generate()
{
    for(int in = 1;in < iter;in++){
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                for(int k = 0;k < N;k++){
                    mat[in][i][j] = (mat[in][i][j] + mat[in - 1][i][k] * mat[in - 1][k][j]) % MOD;
                }
            }
        }
    }
}

LL dp[N][N];
void solve(int n,int p)
{
    MEM(dp,0);
    for(int i = 0;i < N;i++)dp[0][i] = 1;
    int in = 0;
    for(int I = 0;I < iter;I++){
        if(!(p & (1 << I)))continue;
        in = in + 1;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                dp[in][j] += dp[in - 1][i] * mat[I][i][j];
                dp[in][j] %= MOD;
            }
        }
    }
    for(int i = 0;i < n;i++)cout << dp[in][i] << "\n";
}
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        mat[0][a][b] = mat[0][b][a] = 1;
    }
    generate();

    int q,cases = 0;
    cin >> q;
    while(q--){
        int k;cin >> k;
        cout << "Query " << ++cases << ":\n";

        solve(n,k);
    }

}

