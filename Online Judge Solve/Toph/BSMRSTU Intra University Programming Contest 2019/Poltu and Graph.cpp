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


const int N = 200005;

int n , m , q;
deque<pair<int,pii>>edge;
int ans[N],pr[N],seg[N];

int find(int r)
{
    if(pr[r] == r)return r;
    else return pr[r] = find(pr[r]);
}
int main()
{
    scanf("%d %d",&n,&m);
    FOR(i,1,n)pr[i] = i,seg[i] = 1;

    for(int i = 1;i <= m;i++){
        int u , v , w;
        scanf("%d %d %d",&u,&v,&w);
        edge.push_back(mk(w,mk(u,v)));
    }

    scanf("%d",&q);
    deque<pair<int,pii>>que;
    for(int i = 1;i <= q;i++){
        int node , x;
        scanf("%d %d",&node,&x);
        que.push_back(mk(x,mk(node,i)));
    }
    SORT(que);
    SORT(edge);

/*
5 1
1 2 3
4
1 7
1 5
1 3
4 5

*/
    for(int i = 0;i < que.size();i++){
        int x = que[i].first;
//        cout << "x : " << x << "\n";

        while(edge.size() > 0 and edge[0].first <= x){
            int u = edge[0].ss.ff;
            int v = edge[0].ss.ss;
            edge.pop_front();
            u = find(u);
            v = find(v);
            if(u == v)continue;
            seg[u] += seg[v];
            pr[v] = u;
        }
//        for(int j = 1;j <= n;j++)cout << find(j) << " ";cout << "\n";
//        for(int j = 1;j <= n;j++)cout << seg[find(j)] << " ";cout << "\n";
        ans[que[i].ss.ss] = seg[find(que[i].ss.ff)];
    }
    for(int i = 1;i <= q;i++){
        printf("%d\n",ans[i]);
    }

}
