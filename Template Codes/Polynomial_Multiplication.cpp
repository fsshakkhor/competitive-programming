//Codeforces 451E
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

LL n,F[25],s;
vector<vector<pll> >vec;
const LL MOD = 1e9 + 7;
vector<pll> polymul(vector<pll>v1,vector<pll>v2)
{
    map<LL,LL>mp;
    for(int i = 0;i < v1.size();i++){
        for(int j = 0;j < v2.size();j++){
            LL pw = v1[i].second + v2[j].second;
            LL cof = (v1[i].first * v2[j].first ) % MOD;
            mp[pw] += cof;
            mp[pw] %= MOD;
        }
    }
    vector<pll>v;
    for(pll i : mp)v.push_back(mk(i.second % MOD,i.first));
    return v;
}
inline LL BigMod(LL B,LL P,LL M){LL R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}

LL COM(LL a,LL b)
{
    LL ret = 1;
    for(LL i = b + 1;i <= a;i++){
        ret = (ret * (i % MOD) ) % MOD;
    }
    LL down = 1;
    for(int i = 1;i <= a - b;i++){
        down = (down * (i % MOD)) % MOD;
    }
    ret = (ret * BigMod(down,MOD-2,MOD)) % MOD;
    return ret;
}
int main()
{
    FastRead
    cin >> n >> s;
    REP(i,n)cin >> F[i];

    for(int i = 0;i < n;i++){
        vector<pll>v;
        v.push_back(mk(1,0));
        v.push_back(mk(-1,F[i] + 1));
        vec.push_back(v);
    }
    while(vec.size() > 1){
        vector<pll>v1 = vec.back();
        vec.pop_back();
        vector<pll>v2 = vec.back();
        vec.pop_back();
        vec.push_back(polymul(v1,v2));
    }
    vector<pll>v = vec.back();

    LL ans = 0;
    for(int i = 0;i < v.size();i++){
        LL pw = v[i].second;
        LL cof = v[i].first;
        if(pw > s)continue;
        LL need = s - pw;
        LL here = COM(n + need - 1,need);
        ans = ans + (here * cof) % MOD;
        ans %= MOD;
    }
    ans += MOD;
    ans %= MOD;
    cout << ans << "\n";

}

