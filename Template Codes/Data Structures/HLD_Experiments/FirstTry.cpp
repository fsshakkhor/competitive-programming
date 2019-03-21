#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             5e13
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

const int N = 20005;
int n,child[N],pr[N],Lev[N];
int P[N][22];
int id = 1,chainID[N],atPos[N],chainHead[N],cNodes[N];
vector<int>G[N];

int dfs(int node,int pre,int dep)
{
    pr[node] = pre;
    Lev[node] = dep;
    int ret = 1;
    for(int i = 0;i < G[node].size();i++){
        int go = G[node][i];
        if(go == pre)continue;
        ret += dfs(go,node,dep + 1);
    }
    return child[node] = ret;
}
void init()
{
    for(int i = 0;i < N;i++)for(int j = 0;j<22;j++)P[i][j] = 1;
    FOR(i,1,N)P[i][0] = pr[i];

    for(int j = 1;(1 << j) < N;j++){
        for(int i = 0;i < N;i++){
            P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int lca(int p,int q)
{
    if(Lev[p] < Lev[q])swap(p,q);

    for(int i = 21;i>=0;i--){
        if(Lev[P[p][i]] >= Lev[q])p = P[p][i];
    }
    if(p == q)return p;
    for(int i = 21;i>=0;i--){
        if(P[p][i]!=P[q][i]){
            p = P[p][i]; q = P[q][i];
        }
    }
    return pr[p];
}
void input()
{
    scanf("%d",&n);
    for(int i = 1;i < n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        G[a].pb(b);
        G[b].pb(a);
    }
}
struct DATA{
    int l,r,val;
}tree[4 * N];

void update(int node,int L,int R,int pos,int val)
{
    if(pos < L or pos > R)return;
    if(L == R){
        tree[node].val = max(tree[node].val,val);
        return;
    }
    int mid = (L + R)/2;
    if(tree[node].l == 0)tree[node].l = id++;
    if(tree[node].r == 0)tree[node].r = id++;

    int Lnode = tree[node].l;
    int Rnode = tree[node].r;

    update(Lnode,L,mid,pos,val);
    update(Rnode,mid + 1,R,pos,val);

    tree[node].val = max(tree[Lnode].val,tree[Rnode].val);
}

int query(int node,int L,int R,int l,int r)
{
    if(l > r)swap(l,r);
    if(r < L or R < l)return 0;
    if(l <= L and R <= r)return tree[node].val;

    int mid = (L + R)/2;
    int Lnode = tree[node].l;
    int Rnode = tree[node].r;

    int x = query(Lnode,L,mid,l,r);
    int y = query(Rnode,mid+1,R,l,r);
    return max(x,y);
}

queue<int>Q;
void getChain(int node,int cid,int pos,int head)
{
    chainID[node] = cid;
    atPos[node] = pos;
    chainHead[node] = head;
    cNodes[cid]++;

    int heavyChild , sz = 0;
    for(int i = 0;i < G[node].size();i++){
        int go = G[node][i];
        if(go == pr[node])continue;
        if(child[go] > sz){
            sz = child[go];
            heavyChild = go;
        }
    }
    for(int i = 0;i < G[node].size();i++){
        int go = G[node][i];
        if(go == pr[node])continue;
        if(go == heavyChild)getChain(go,cid,pos + 1,head);
        else Q.push(go);
    }
}

void process()
{
    dfs(1,1,0);
    init();

    Q.push(1);
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        getChain(node,id++,1,node);
    }
    for(int i = 1;i <= n;i++){
        update(chainID[i],1,cNodes[chainID[i]],atPos[i],i);
    }
}

int Get(int p,int q)
{
    if(chainID[p] == chainID[q]){
        return query(chainID[p],1,cNodes[chainID[p]],atPos[p],atPos[q]);
    }else{
        int H = chainHead[p];
        int mx = query(chainID[p],1,cNodes[chainID[p]],atPos[p],atPos[H]);
        return max(mx,Get(pr[H],q));
    }
}
int main()
{
    input();
    process();

    int a,b;
    while(cin >> a >> b){
        cout << Get(a,b) << endl;
    }


}
/*
11
1 2
2 5
2 6
6 8
8 10
8 11
1 3
3 7
7 9
1 4

*/
