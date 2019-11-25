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
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);

const int N = 300005;
int id = 4 * N;
int trie[21 * 21 * N][2];

void insert(int num,int row){
    for(int i = 20;i >= 0;i--){
        bool d = num & (1 << i);
        if(trie[row][d] == 0){
            trie[row][d] = ++id;
        }
        row = trie[row][d];
    }
}
int search(int num,int row)
{
    int val = 0;
    for(int i = 20;i >= 0;i--){
        bool d = num & (1 << i);
        if(trie[row][1 - d]){
            row = trie[row][1 - d];
            val = val | (1 << i);
        }else{
            row = trie[row][d];
        }
    }

    return val;
}

int n , q , ara[N];

void build(int node,int L,int R)
{
    for(int i = L;i <= R;i++)insert(ara[i],node);

    if(L == R)return;
    int mid = (L + R)/2;
    build(2 * node,L,mid);
    build(2 * node + 1,mid + 1,R);
}
int query(int node,int L,int R,int l,int r,int x)
{
    if(R < l or r < L)return 0;
    if(L >= l and R <= r){
        return search(x,node);
    }
    int mid = (L + R)/2;
    int a = query(2 * node,L,mid,l,r,x);
    int b = query(2 * node + 1,mid + 1,R,l,r,x);
    return max(a,b);
}

int main()
{
    scanf("%d",&n);
    FOR(i,1,n)scanf("%d",&ara[i]);
    build(1,1,n);
    scanf("%d",&q);
    while(q--){
        int l , r , x;
        scanf("%d %d %d",&l,&r,&x);
        printf("%d\n",query(1,1,n,l,r,x));
    }

}
