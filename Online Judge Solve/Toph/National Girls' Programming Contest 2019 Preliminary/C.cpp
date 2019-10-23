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
#define PI              2 * acos(0.0)
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
int n , r;
int ara[N];
int cnt[N];
int main()
{
    scanf("%d %d",&n,&r);
    FOR(i,1,n)scanf("%d",&ara[i]);

    set<int>st;
    FOR(i,1,n)st.insert(ara[i]);
    int ans = 0;
    while(st.size() > 0){
        ans++;
        int Last = *(--st.end());
        st.erase(--st.end());
        while(st.size() > 0){
            int V = *(--st.end());
            if(ABS(V - Last) <= r){
                st.erase(--st.end());
                if(V - r > 0)st.insert(V - r);
            }
            else break;
        }
    }
    cout << ans << "\n";

}
