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

int n;
int mark[71];
int ara[71],sz,ans;
int Ans[71];
int Maximum[71];
void rec(int pos)
{
    if(sz > ans){
        ans = sz;
        for(int i = 0;i < ans;i++)Ans[i] = ara[i];
    }
    if(sz + n - pos + 1 <= ans)return;
    if(Maximum[n - pos + 1] + sz <= ans)return;
    if(pos == n + 1)return;
    if(mark[pos] == 0){

        for(int i = sz-1;i >=0;i--){
            int d = pos - ara[i];
            int ele = pos + 2 * d;
            if(ele > n)break;
            mark[ele]++;
        }
        ara[sz++] = pos;
        rec(pos + 1);
        sz--;
        for(int i = sz-1;i >=0;i--){
            int d = pos - ara[i];
            int ele = pos + (d << 1);
            if(ele > n)break;
            mark[ele]--;
        }
    }
    rec(pos + 1);
}
int main()
{
    fRead("art.in");
    fWrite("art.out");
    const clock_t begin_time = clock();
    for(int i = 1;i <= 70;i++)Maximum[i] = 100;
    int X;
    cin >> X;
    for(n = 1;n <= X;n++){
        rec(1);

        Maximum[n] = ans;
    }
    cout << ans << "\n";
    for(int i = 0;i < ans;i++)
    {
        if(i)cout << " ";
        cout << Ans[i];
    }cout << "\n";
//    cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;

}
