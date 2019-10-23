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

const int N = 1005;
int n,q;
int X[N],Y[N];

struct DATA{
    int u , v, w;
};
vector<DATA>edge;
bool cmp(DATA a,DATA b)
{
    return a.w < b.w;
}
double ans[N];
int pr[N];

int find(int r)
{
    if(pr[r] == r)return r;
    else return pr[r] = find(pr[r]);
}
int main()
{
    cin >> n;
    FOR(i,1,n)cin >> X[i] >> Y[i];
    FOR(i,1,n)pr[i] = i;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            edge.push_back({i,j,SQR(X[i] - X[j]) + SQR(Y[i] - Y[j])});
        }
    }
    sort(edge.begin(),edge.end(),cmp);

    vector<pii>Q;
    cin >> q;
    FOR(i,1,q)
    {
        int w;cin >> w;
        Q.push_back(mk(w,i));
    }
    SORT(Q);
    REV(Q);

    int ptr = 0;
    int kingdom = n;
    int cur = 0;
    for(int i = 0;i < Q.size();i++){
        while(kingdom > Q[i].first){
            int u = edge[ptr].u;
            int v = edge[ptr].v;
            int w = edge[ptr].w;
            u = find(u);
            v = find(v);
            ptr = ptr + 1;
            if(u == v)continue;
            kingdom--;
            pr[v] = u;
            cur = w;
        }
        ans[Q[i].second] = cur;
    }
    for(int i = 1;i <= q;i++){
        cout << fixed << setprecision(9) << sqrt(ans[i]) << "\n";
    }
}
