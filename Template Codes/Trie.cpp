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
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

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

const LL MOD = 1e9 + 7;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> inline T BigMod(T A,T B,T M = MOD){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T EGCD(T a,T b,T &x,T &y){if(a == 0) {x = 0;y = 1;return b;}T x1, y1;T d = EGCD(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
template <typename T> inline T LCM(T x,T y){T g = __gcd(x,y);return (x/g)*y;}
template <typename T> inline T Distance(T x1, T y1, T x2, T y2){return sqrt(SQR(x1 - x2) + SQR(y1 - y2));}
template <typename T> inline T Area(T Ax, T Ay, T Bx, T By, T Cx, T Cy){T ret = Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By);if(ret < 0) return ret = -ret;return ret;}

bool Check(int num,int pos){return (bool)(num & (1<<pos));}
int Set(int num,int pos){	return num=num | (1<<pos);}
int fx[] = {-1,+0,+1,+0,+1,+1,-1,-1,+0};
int fy[] = {+0,-1,+0,+1,+1,-1,+1,-1,+0};

template <typename T> inline T CRT(T num[], T rem[], T k)
{
    T prod = 1,result=0;
    for (T i = 0; i < k; i++)prod *= num[i];
    for (T i = 0; i < k; i++){T pp = prod / num[i];result += rem[i] * inv(pp, num[i]) * pp;}
    return result % prod;
}

const int FacN = 1000000;
LL Fac[FacN+5];
void Facgen(){Fac[0] = 1; FOR(i,1,FacN)Fac[i] = (Fac[i-1]*i) % MOD;}
template <typename T> inline T COM(T a,T b)
{
    if(a<b)return 0;
    return ((Fac[a] * BigMod( (Fac[b]*Fac[a-b])%MOD , MOD-2 , MOD) )%MOD + MOD ) % MOD;
}

/// ***********************************END****************************************///
const int N = 200000;
int id = 1,trie[32 * N + 5][2] , mark[32 * N + 5];

void Insert(int num)
{
    int row = 1;
    for(int i = 30;i>=0;i--){
        int d = Check(num,i);
        if(trie[row][d]==0){
            trie[row][d]=++id;
        }
        row = trie[row][d];
        mark[row]++;
    }
}

void Del(int num)
{
    int row = 1;
    deque<int>v;
    for(int i = 30;i>=0;i--){
        int d = Check(num,i);
        v.push_front(row);
        row = trie[row][d];
        mark[row]--;
    }
    v.push_front(row);

    for(int i = 1;i<v.size();i++){
        if(mark[v[i-1]]==0){
            if(trie[v[i]][0]==v[i-1])trie[v[i]][0] = 0;
            if(trie[v[i]][1]==v[i-1])trie[v[i]][1] = 0;
        }
    }
}
int main()
{
    FastRead
    int q;
    cin >> q;
    Insert(0);
    while(q--)
    {
        char ch; int num;
        cin >> ch >> num;

        if(ch=='+'){
            Insert(num);
        }
        else if(ch=='-'){
            Del(num);
        }else{
            int row = 1;
            int number = 0;
            for(int i = 30;i>=0;i--){
                int d = Check(num,i);
                if(trie[row][1-d]!=0){
                    row = trie[row][1-d];
                    number += (1 << i);
                }
                else row = trie[row][d];
            }
            cout << number << "\n";
        }
    }
}
