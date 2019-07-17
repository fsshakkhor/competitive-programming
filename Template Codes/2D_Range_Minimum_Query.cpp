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
 
const int N = 3005;
int g[N * N];
LL x,y,z;
int ara[N][N];
int Rows[N][N];
int Cols[N][N];
int n , m, a , b;
 
int main()
{
    cin >> n >> m >> a >> b;
    cin >> g[0] >> x >> y >> z;
    for(int i = 1;i <= n * m;i++)g[i] = (g[i-1] * x + y) % z;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ara[i - 1][j - 1] = -g[(i-1)*m+j-1];
        }
    }
 
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        q.clear();
 
        int j;
        for (j = 0; j < b; ++j) {
            while (!q.empty() && ara[i][j] >= ara[i][q.back()]) {
                //cout << "a: " << i << ' ' << j << ' ' << ara[i][j] << '\n';
                q.pop_back();
            }
            q.push_back(j);
        }
 
        for ( ; j < m; ++j) {
            Rows[i][j-b] = ara[i][q.front()];
 
            while (!q.empty() && q.front() <= j - b) {
                q.pop_front();
            }
 
            while (!q.empty() && ara[i][j] >= ara[i][q.back()]) {
                q.pop_back();
            }
            q.push_back(j);
        }
        Rows[i][j-b] = ara[i][q.front()];
    }
    for (int j = 0; j + b - 1 < m; ++j) {
        q.clear();
 
        int i;
        for (i = 0; i < a; ++i) {
            while (!q.empty() && Rows[i][j] >= Rows[q.back()][j]) {
                q.pop_back();
            }
            q.push_back(i);
        }
 
        for ( ; i < n; ++i) {
            Cols[i-a][j] = Rows[q.front()][j];
 
            while (!q.empty() && q.front() <= i - a) {
                q.pop_front();
            }
 
            while (!q.empty() && Rows[i][j] >= Rows[q.back()][j]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        Cols[i-a][j] = Rows[q.front()][j];
    }
    LL ans = 0;
//    cout << a << " " << b << "\n";
    for (int i = 0; i + a - 1 < n; ++i) {
        for (int j = 0; j + b - 1 < m; ++j) {
            ans += -Cols[i][j];
//            cout << -Cols[i][j] << " ";
        }
//        cout << "\n";
    }
    cout << ans << "\n";
 
}
