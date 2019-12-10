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


LL dp[16][10][2][2];
int vis[16][10][2][2],visId;
string str;

string gen(LL n)
{
    string s;
    while(n > 0){
        s += char('0' + n % 10);
        n/=10;
    }
    while(s.size() < 15)s += "0";
    REV(s);
    return s;
}
LL call(int pos,int pre,int tight,int ff)
{

    if(pos == str.size())return ff == 0;
    if(tight == 0 and vis[pos][pre][tight][ff] > 0)return dp[pos][pre][tight][ff];
    if(vis[pos][pre][tight][ff] == visId)return dp[pos][pre][tight][ff];
    vis[pos][pre][tight][ff] = visId;

    int lo = 0 , hi = 9;
    if(tight == 1)hi = str[pos] - '0';
    if(ff == 0)lo = 1;

    LL ret = 0;
    for(int i = lo;i <= hi;i++){
        if(i == pre){
            if(i != 0)continue;
        }
        int newtight = tight;
        if(i != hi)newtight = 0;
        ret = ret + call(pos + 1,i,newtight,(ff && (i == 0)));
    }
    return dp[pos][pre][tight][ff] = ret;

}
int main()
{
    FastRead
    int t,cases = 0;
    cin >> t;

    while(t--){
        LL n;
        cin >> n;
        LL lo = 1, hi = 1e14 , mid,ans;

        while(lo <= hi){
            mid = (lo + hi)/2;
            str = gen(mid);
            visId++;
            LL got = call(0,0,1,1);
            if(got >= n){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        cout << "Case " << ++cases << ": " << ans << "\n";
    }
}
