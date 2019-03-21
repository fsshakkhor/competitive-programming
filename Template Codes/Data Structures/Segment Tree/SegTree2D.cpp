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
#define pii pair<int,int>
#define pll pair<LL,LL>


#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,b) for(int i=0;i<b;++i)
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

LL treesum[6000005];

inline void buildsum(int at,int x1,int y1,int x2,int y2,int x,int y,int val)
{
    if(x1>x2 or y1>y2)return;

    if(x<x1 or x>x2 or y<y1 or y>y2)return;

    if(x1==x2 and y1==y2)
    {
        treesum[at] = val;
        return;
    }
    int mx = (x1+x2)/2;
    int my = (y1+y2)/2;

    buildsum(4*at,x1,y1,mx,my,x,y,val);

    buildsum(4*at+1,x1,my+1,mx,y2,x,y,val);

    buildsum(4*at+2,mx+1,y1,x2,my,x,y,val);

    buildsum(4*at+3,mx+1,my+1,x2,y2,x,y,val);

    treesum[at] = treesum[4*at]+treesum[4*at+1]+treesum[4*at+2]+treesum[4*at+3];
    return;
}

inline int tellsum(int at,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    if(x1>x2 or y1>y2)return 0;


    if(x4<x1 or y4<y1 or x3>x2 or y3>y2)return 0;

    if(x1>=x3 and x2<=x4 and y1>=y3 and y2<=y4)
    {
        return treesum[at];
    }
    int mx = (x1+x2)/2;
    int my = (y1+y2)/2;

    int a = tellsum(4*at,x1,y1,mx,my,x3,y3,x4,y4);
    int b = tellsum(4*at+1,x1,my+1,mx,y2,x3,y3,x4,y4);
    int c = tellsum(4*at+2,mx+1,y1,x2,my,x3,y3,x4,y4);
    int d = tellsum(4*at+3,mx+1,my+1,x2,y2,x3,y3,x4,y4);

    return (a+b+c+d);
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        MEM(treesum,0);
        int n;
        scanf("%d",&n);
        char str[10];
        while(scanf("%s",str)){
            if(str[1]=='N')break;
            if(str[1]=='E'){
                int x,y,v;
                scanf("%d %d %d",&x,&y,&v);
                buildsum(1,0,0,n-1,n-1,x,y,v);
            }else{
                int x1,y1,x2,y2;
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                printf("%lld\n",tellsum(1,0,0,n-1,n-1,x1,y1,x2,y2));
            }
        }
        printf("\n");
    }

}
