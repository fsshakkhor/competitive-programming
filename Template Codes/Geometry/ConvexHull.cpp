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

double eps = 1e-12;

typedef complex<double> pt;
#define x real()
#define y imag()

double cross(pt v, pt w) {return (conj(v)*w).y;}///No Dependency

double area2(pt a, pt b, pt c) ///Dependency : cross
{
    return cross(a,b) + cross(b,c) + cross(c,a);
}

bool between(const pt &a, const pt &b, const pt &c)///Dependency : cross,area2
{
    return (fabs(area2(a,b,c)) < eps && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}

bool cmp(pt &a,pt &b)
{
    if(a.x != b.x)return a.x < b.x;
    return a.y < b.y;
}
#define REMOVE_REDUNDANT
void ConvexHull(vector<pt> &pts)
{
    sort(pts.begin(), pts.end(),cmp);
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<pt> up, dn;
    for (int i = 0; i < pts.size(); i++)
    {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++)
    {
        if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1]))
    {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
#endif
}

int main()
{
    int n;
    while(cin >> n){
        if(n < 3)break;
        vector<pt>pts;
        for(int i = 1;i <= n;i++){
            int a,b;
            cin >> a >> b;
            pts.push_back(pt(a,b));
        }
        ConvexHull(pts);
    }



}
