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
#define REP(i,b) for(int i=0;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
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

const int N = 100005;
struct data {
    int l, r, c;
    data() {
        l = r;
        c = 1e9;
    }
    data(int a, int b, int d) {
        l = a;
        r = b;
        c = d;
    }
}T[N * 20];

int n, in[N], Root[N], id, qr;

int update(int pr, int b, int e, int pos,int val) {
    int node = ++id;
    T[node] = T[pr];
    if(b == e) {
        T[node].c = val;
        return node;
    }
    int mid = b + e >> 1;
    if(pos <= mid) T[node].l = update(T[node].l, b, mid, pos,val);
    else T[node].r = update(T[node].r, mid + 1, e, pos,val);
    T[node].c = min(T[ T[node].l ].c , T[ T[node].r ].c);
    return node;
}

int query(int pr,int b, int e, int l,int r) {
    if(e < l or r < b)return 1e9;
    if(b >= l and e <= r) return T[pr].c;

    int mid = b + e >> 1;
    int x = query(T[pr].l,b,mid,l,r);
    int y = query(T[pr].r,mid+1,e,l,r);
    return min(x,y);
}

int timer,st[N],ed[N],ara[N],Lev[N];
vector<int>nodes[N],g[N];
void dfs(int node,int pre,int L)
{
    st[node] = ++timer;
    Lev[node] = L;
    ara[timer] = in[node];
    nodes[L].push_back(st[node]);
    for(int i : g[node]){
        if(i == pre)continue;
        dfs(i,node,L + 1);
    }
    ed[node] = timer;
}


int levelTime[N];
int main()
{
    int n , r;
    scanf("%d %d",&n,&r);
    for(int i = 1;i <= n;i++)scanf("%d",&in[i]);

    for(int i = 1;i < n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(r,r,0);
    Root[0] = ++id;
    int lt = 0;
    int highest = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < nodes[i].size();j++){
            int node = nodes[i][j];
            lt++;
            Root[lt] = update(Root[lt - 1],1,n,node,ara[node]);
            levelTime[i] = lt;
            highest = i;
        }
    }

    int m;
    scanf("%d",&m);
    int ans = 0;
    while(m--){
        int p,q;
        scanf("%d %d",&p,&q);
        int x = (p + ans) % n + 1;
        int k = (q + ans) % n;
        k = k + Lev[x];
        k = min(k,highest);
        ans = query(Root[levelTime[k]],1,n,st[x],ed[x]);
        printf("%d\n",ans);
    }
}
/*
5
1 5
2 4
3 3
4 2
5 1
*/
