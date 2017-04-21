#include<bits/stdc++.h>

using namespace std;

#define fRead(x)  freopen(x,"r",stdin)
#define fWrite(x) freopen (x,"w",stdout)

#define LL long long
#define ULL unsigned long long
#define ff first
#define ss second
#define pb push_back
#define INF 2e16
#define PI acos(-1.0)
#define mk make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>


#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,b) for(int i=0;i<b;i++)
#define MEM(a,x) memset(a,x,sizeof(a))
#define ABS(x) ((x)<0?-(x):(x))

#define scanI(a) scanf("%d",&a)
#define scanI2(a,b) scanI(a) , scanI(b)
#define scanI3(a,b,c) scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a) scanf("%I64d",&a)
#define scanL2(a,b) scanL(a) , scanL(b)
#define scanL3(a,b,c) scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

#define SORT(v) sort(v.begin(),v.end())
#define REV(v) reverse(v.begin(),v.end())


#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);

void doLIS(const vector<int> &S, vector<int> &LIS)
{
    vector<int> L(S.size());
    int lisCount = 0;
    for (int i = 0; i < S.size(); ++i)
    {
        int pos = lower_bound(L.begin(), L.begin() + lisCount, S[i])
                     - L.begin();
        L[pos] = S[i];
        if (pos == lisCount)
            ++lisCount;

        LIS[i] = pos + 1;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        vector<int>v(n);
        for(int i = 0;i<n;i++)scanf("%d",&v[i]);
        vector<int>inc(n),dec(n);

        doLIS(v,inc);
        getchar();
        getchar();
        REV(v);
        doLIS(v,dec);
        REV(dec);
        int mx = 0;
        for(int i = 0;i<inc.size();i++){
            mx = max(mx,2*min(inc[i],dec[i])-1);
        }
        printf("%d\n",mx);

    }


}
