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
#define all(a) a.begin(), a.end()

const int N = 100000;
struct info{
    int val,lazy = -1;
}tree[26][4*N];

void pushDown(int id,int at,int L,int R)
{
    if(tree[id][at].lazy == -1)return;
    if(tree[id][at].lazy == 0){
        tree[id][at].val = 0;
    }else{
        tree[id][at].val = R - L + 1;
    }

    if(L != R){
        tree[id][2*at].lazy = tree[id][at].lazy;
        tree[id][2*at+1].lazy = tree[id][at].lazy;
    }
    tree[id][at].lazy = - 1;
}

void update(int id,int at,int L,int R,int l,int r,int v)
{
    pushDown(id,at,L,R);

    if(L > R or L > r or R < l)return;

    if(L>=l and R<=r){
        tree[id][at].lazy = v;
        pushDown(id,at,L,R);
        return;
    }
    int mid = (L + R)/2;
    update(id,2*at,L,mid,l,r,v);
    update(id,2*at+1,mid+1,R,l,r,v);
    tree[id][at].val = tree[id][2*at].val + tree[id][2*at+1].val;
}

int query(int id,int at,int L,int R,int l,int r)
{
    if(L > R or L > r or R < l)return 0;
    pushDown(id,at,L,R);
    if(L>=l and R<=r)return tree[id][at].val;
    int mid = (L+R)/2;
    int p1 = query(id,2*at,L,mid,l,r);
    int p2 = query(id,2*at+1,mid+1,R,l,r);
    return p1 + p2;
}

int main()
{

}
