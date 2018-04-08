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
map<pii,int>mp;
int n,m,id;
set<int>state[N];
vector<int>G[N];

struct INFO{
   int a,b,c;
}ara[N];

struct data{
   int l,r,val;
}tree[24 * N];

 void update(int node,int L,int R,int pos,int val)
{
   if(pos < L or pos > R)return;

//   cout << node << " " << L << " " << R << " " << pos << " " << val << endl;
   if(L == R){
      tree[node].val = max(tree[node].val,val);
      return;
   }
   int mid =(L + R)/2;
   if(tree[node].l == 0)tree[node].l = ++id;
   if(tree[node].r == 0)tree[node].r = ++id;

   update(tree[node].l,L,mid,pos,val);
   update(tree[node].r,mid + 1,R,pos,val);

   tree[node].val = max(tree[tree[node].l].val , tree[tree[node].r].val);
}

 int query(int node,int L,int R,int l,int r)
{
   if(l > r)return 0;
   if(r < L or R < l)return 0;

   if(l <= L and R <= r)return tree[node].val;

   int mid = (L + R)/2;

   int x = query(tree[node].l,L,mid,l,r);
   int y = query(tree[node].r,mid + 1,R,l,r);
   return max(x,y);

}

int main()
{
   id = 2e5 +  2;
   scanf("%d %d",&n,&m);

   FOR(i,1,m)
   {
      scanf("%d %d %d",&ara[i].a,&ara[i].b,&ara[i].c);
      int a = ara[i].a;
      int b = ara[i].b;
      int c = ara[i].c;
      G[a].push_back(c);
   }
   FOR(i,1,n)SORT(G[i]);
//   FOR(i,1,n)
//   {
//      for(int j : G[i])cout << j << " ";
//      cout << endl;
//   }
//   cout << endl;
   int answer = 0;
   for(int i = m;i >= 1;i--){ ///Change
      int a = ara[i].a;
      int b = ara[i].b;
      int c = ara[i].c;
      auto it = state[b].upper_bound(c);

      if(it == state[b].end()){
         int p = lower_bound(G[a].begin(),G[a].end(),c) - G[a].begin();
//         cout << "id " << i <<  " position " << p << endl;
         update(a,0,200000,p,1);
//         cout << query(a,0,200000,0,p) << endl;
         answer = max(answer,1);
         state[a].insert(c);
      }else{
         int p = lower_bound(G[a].begin(),G[a].end(),c) - G[a].begin();
         int p2 = lower_bound(G[b].begin(),G[b].end(),*it) - G[b].begin();
         int got = query(b,0,200000,p2,200000);
//         cout << "id " << i << " positions " << p << " " << p2 << " got " << got << endl;
         answer = max(answer,got + 1);
         update(a,0,200000,p,got + 1);
         state[a].insert(c);
      }
   }
   printf("%d\n",answer);


}
