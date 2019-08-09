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

bool isLinear(vector<pt>&pts,int x1,int y1,int x2,int y2)
{
    int n = pts.size();
    for(int i = 0;i < pts.size();i++){
        if(ABS(area2(pts[i],pt(x2,y2),pt(x1,y1))) < eps)return 0;
    }
    return 1;
}
double orient(pt a,pt b,pt c)
{
    return cross(b-a,c-a);
}
bool segmentToSegment(pt a,pt b,pt c,pt d,pt &out)
{
    double oa = orient(c,d,a);
    double ob = orient(c,d,b);
    double oc = orient(a,b,c);
    double od = orient(a,b,d);

    if(oa * ob < 0 && oc * od < 0){
        out = (a * ob - b * oa)/(ob - oa);
        return true;
    }
    return false;
}
bool pointInsidePolygon(vector<pt>&pts,int x1,int y1) ///pts contains set of points of non-convex polygon
{                                                    /// (x1,y1) query point
    int x2 = 1e9,y2 = 1e8;
    while(!isLinear(pts,x1,y1,x2,y2)){
        y2--;
    }
    int inc = 0;
    int n = pts.size();
    for(int i = 0;i < pts.size();i++){
        pt out;
        if(segmentToSegment(pts[i],pts[(i+1)%n],pt(x1,y1),pt(x2,y2),out))inc = 1 - inc;
    }
    return inc;
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
        int x1,y1;cin >> x1 >> y1;
        bool flag = pointInsidePolygon(pts,x1,y1);
        if(flag)cout << "T\n";
        else cout << "F\n";
    }



}
