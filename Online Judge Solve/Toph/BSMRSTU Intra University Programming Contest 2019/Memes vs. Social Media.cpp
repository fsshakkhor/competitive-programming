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

const int N = 100005;
int pr[N],seg[N],dp[N],possible[N];
int find(int r)
{
    if(pr[r] == r)return r;
    else return pr[r] = find(pr[r]);
}
int main()
{
    int n , m , k;
    scanf("%d %d %d",&n,&m,&k);
    FOR(i,1,n)pr[i] = i,seg[i] = 1;
    FOR(i,1,m)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int u = find(a);
        int v = find(b);
        if(u > v)swap(u,v);
        if(u == v)continue;
        pr[v] = u;
        seg[u] += seg[v];
    }
    vector<pii>vec;
    for(int i = 1;i <= n;i++){
        if(find(i) == i){
            vec.push_back(mk(seg[i],i));
        }
    }
    FOR(i,1,n)dp[i] = 1e9;
    for(int i = 0;i < vec.size();i++){
        int cost = vec[i].second;
        int val = vec[i].first;
//        cout << "v c : " << cost << " " << val << "\n";
        for(int j = n;j >= val;j--){
            dp[j] = min(dp[j],cost + dp[j - val]);
//            cout << j << " " << dp[j] << "\n";
        }
    }
    int ans = 1e9;
    for(int i = k;i <= n;i++)ans = min(ans,dp[i]);
    cout << ans << "\n";
}
