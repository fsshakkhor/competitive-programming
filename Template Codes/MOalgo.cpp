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

const int N = 200000;
int ara[N+5];
int oc[1000005];
struct data
{
    int l,r,id;
};
data Q[N+5];
LL answer[N+5];
int sq;
bool cmp(data A,data B)
{
    if(A.l/sq!=B.l/sq)return A.l/sq < B.l/sq;
    return A.r<B.r;
}
LL value;
LL add(int pos)
{
    LL X = oc[ara[pos]];
    value -= X*X*ara[pos];
    X = ++oc[ara[pos]];
    value += X*X*ara[pos];
}
LL remove(int pos)
{
    LL X = oc[ara[pos]];
    value -= X*X*ara[pos];
    X = --oc[ara[pos]];
    value += X*X*ara[pos];
}

int main()
{
    int n;
    int q;
    scanf("%d",&n);
    scanf("%d",&q);
    sq = sqrt(n);
    for(int i = 0;i<n;i++)scanf("%d",&ara[i]);

    for(int i = 0;i<q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        Q[i].l=l-1;
        Q[i].r=r-1;
        Q[i].id=i;
    }
    sort(Q,Q+q,cmp);

    int mol = 0;
    int mor = -1;
    for(int i = 0;i<q;i++){
        int l = Q[i].l;
        int r = Q[i].r;

        while(mor < r){
            mor++;
            add(mor);
        }
        while(mor > r){
            remove(mor);
            mor--;
        }
        while(mol < l){
            remove(mol);
            mol++;
        }

        while(mol>l){
            mol--;
            add(mol);
        }

        answer[Q[i].id]=value;
    }

    for(int i = 0;i<q;i++){
        printf("%I64d\n",answer[i]);
    }

}
