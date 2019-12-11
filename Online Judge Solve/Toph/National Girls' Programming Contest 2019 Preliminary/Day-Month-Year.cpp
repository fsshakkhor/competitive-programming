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

const int N = 100005;
const LL MOD = 1e9 + 7;
LL dp[N],pw[N];
LL pre[301][27][31];
int sz[6];

void preprocess()
{
    for(int i = 1;i <= 300;i++){
        for(int j = 1;j <= 26;j++){
            vector<int>v;
            int temp = j;
            while(temp > 0){
                v.push_back(temp % 10);
                temp/=10;
            }
            temp = i;
            while(temp > 0){
                v.push_back(temp % 10);
                temp/=10;
            }
            sz[v.size()]++;
        }
    }
}
LL check(int day,int month,int n)
{
    if(pre[day][month][n] != -1)return pre[day][month][n];
    vector<int>v;
    int temp = month;
    while(temp > 0){
        v.push_back(temp % 10);
        temp/=10;
    }
    temp = day;
    while(temp > 0){
        v.push_back(temp % 10);
        temp/=10;
    }
    REV(v);
    if(v.size() + 1 > n)return pre[day][month][n] = 0;

    LL ret = 1;

    int mid = (n + 1)/2 - 1;

    int l = 0, r = n - 1;

    while(l <= r){

        if(l >= v.size()){
            int dif = mid - l + 1;
            if(r < v.size() and v[r] == 0)ret = 0;
            else ret = (ret * 9) % MOD;

            ret = (ret * pw[dif - 1]) % MOD;
            return pre[day][month][n] = ret % MOD;
        }

        if(r == v.size() and l < v.size() and v[l] == 0)return pre[day][month][n]  = 0;
        if(r < v.size()){
            if(v[l] != v[r])return pre[day][month][n] = 0;
        }
        l++;r--;
    }
    return pre[day][month][n] = ret;
}
LL solve(int n)
{
    if(dp[n] != -1)return dp[n];
    LL ret = 0;
    if(n <= 20){
        for(int day = 1;day <= 300;day++){
            for(int month = 1;month <= 26;month++){
                int save = check(day,month,n);
                ret = (ret + save) % MOD;
            }
        }
        return dp[n] = ret;
    }else{
        int mid = (n + 1)/2;
        LL ret = 0;
        for(int i = 1;i <= 5;i++){
            int dif = mid - i ;
            ret = (ret + pw[dif - 1] * 9 * sz[i]) % MOD;
        }
        return dp[n] = ret;
    }
}
int main()
{
    preprocess();
    MEM(dp,-1);
    MEM(pre,-1);
    pw[0] = 1;
    FOR(i,1,N - 1)pw[i] = (pw[i - 1] * 10) % MOD;

    int t,cases = 0;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);

        printf("Case %d: %lld\n",++cases,solve(n));
    }

}
