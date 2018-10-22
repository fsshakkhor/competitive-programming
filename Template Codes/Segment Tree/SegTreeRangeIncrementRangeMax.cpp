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
struct info{
    int lazy,maxv;
}tree[4 * N];

void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(tree[node].lazy != 0)
    {
        tree[node].maxv += tree[node].lazy;

        if(start != end)
        {
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2+1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
    if(start > end or start > r or end < l)return;

    if(start >= l and end <= r)
    {
        tree[node].maxv += val;
        cout << "update " << start << " " << end << " " << tree[node].maxv << endl;
        if(start != end)
        {
            tree[node*2].lazy += val;
            tree[node*2+1].lazy += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    tree[node].maxv = max3(tree[node].maxv,tree[node * 2].maxv,tree[node * 2 + 1].maxv);
    cout << "update " << start << " " << end << " " << tree[node].maxv << endl;
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)return 0;

    if(tree[node].lazy != 0)
    {
        tree[node].maxv += tree[node].lazy;

        if(start != end)
        {
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2+1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    if(start >= l and end <= r)return tree[node].maxv;

    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
    cout << "query " << start << " " << end << " " << p1 << " " << p2 << endl;
    return max(p1,p2);
}

pii ara[N];
int tp[N];
int main()
{
    int t;
    int cases = 0;
    scanf("%d",&t);

    while(t--){
        MEM(tree,0);
        int n,id = 1;
        scanf("%d",&n);

        map<int,int>mp;
        set<int>st;
        for(int i = 0;i < n;i++){
            scanf("%d",&tp[i]);
            scanf("%d %d",&ara[i].first,&ara[i].second);
            assert(ara[i].first < ara[i].second);
            st.insert(ara[i].first);
            st.insert(ara[i].second);
        }
        id = 0;
        for(int i : st){
            mp[i] = ++id;
        }
        for(int i = 0;i < n;i++){
            ara[i].first = mp[ara[i].first];
            ara[i].second = mp[ara[i].second];
        }
        printf("Case %d:\n",++cases);
        for(int i = 0;i < n;i++){
            if(tp[i] == 1){
                updateRange(1,1,id,ara[i].first,ara[i].second,1);
            }else{
                int ans = queryRange(1,1,id,ara[i].first,ara[i].second);
                printf("%d\n",ans);
            }
        }

    }
}
/*

1
4
1 1 2
2 1 2
1 3 4
2 1 4
*/
