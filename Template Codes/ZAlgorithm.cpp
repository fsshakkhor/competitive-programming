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

const int N = 1000005;
int Z[N];
int n,m;
string str;
void Function()
{
    int L = 0, R = 0 , k ,n = str.size();
    for(int i = 1;i < n;i++){
        if(i > R){
            L = R = i;
            while (R<n && str[R-L] == str[R])R++;
            Z[i] = R-L;
            R--;
        }else{
            k = i - L;
             if (Z[k] < R-i+1)Z[i] = Z[k];
             else{
                L = i;
                while (R<n && str[R-L] == str[R])R++;
                Z[i] = R-L;
                R--;
             }
        }
    }
}
int ara[N];
int got[N];
int main()
{
    FastRead
    cin >> n >> m;
    cin >> str;
    Function();
    FOR(i,1,m)cin >> ara[i];

//    for(int i = 0;i < str.size();i++)cout << Z[i] << " ";
//    cout << endl;
    for(int i = 2;i <= m;i++){
        int a = ara[i-1];
        int b = ara[i];
        int len = b - a;
        int baki = str.size() - len;

        if(baki > Z[len]){
            cout << 0 << endl;
            return 0;
        }
    }
    LL MOD = 1e9 + 7;
    for(int i = 1;i <= m;i++){
        got[ara[i]]++;
        got[ara[i]+str.size()]--;
    }
    int s = 0;
    LL ans = 1;
    for(int i = 1;i <= n;i++){
        s = s + got[i];
        if(s == 0)ans = (ans * 26) % MOD;
    }
    cout << ans << endl;
}
