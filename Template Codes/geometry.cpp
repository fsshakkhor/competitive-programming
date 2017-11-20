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
#define SQ(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define MAXD 3
#define eps 1e-9


double cosineRule3Side ( double a, double b, double c ) {
    double res = (SQ(a)+SQ(b)-SQ(c)) / (2*a*b);
    if ( res < -1 ) res = -1; if ( res > 1 ) res = 1;
    return acos ( res );
}
struct myVec {
    int d; ///Dimension
    double val[MAXD];///Contains value of each component

    myVec(){
      d = 3;
    }
    myVec(double a,double b,double c){
      d = 3;
      val[0] = a; val[1] = b; val[2] = c;
    }
    myVec(double a,double b){
      d = 2;
      val[0] = a; val[1] = b;
    }
    myVec add ( myVec b ) {
        myVec res;
        FOR(i,0,d-1) res.val[i] = val[i] + b.val[i];
        return res;
    }
    myVec sub ( myVec b ) {
        myVec res; FOR(i,0,d-1) res.val[i] = val[i] - b.val[i];return res;
    }
    myVec mul ( double t ) {
        myVec res; FOR(i,0,d-1)res.val[i] = val[i] * t;return res;
    }
    myVec div ( double t ) {
        myVec res; FOR(i,0,d-1) res.val[i] = val[i] / t;return res;
    }
    bool operator == ( myVec b ) {
        FOR(i,0,d-1) if ( fabs ( val[i] - b.val[i] ) > eps ) return false; return true;
    }
    myVec perp2D() {
        myVec res = (*this);
        swap ( res.val[0], res.val[1] );
        res.val[0] *= -1;
        return res;
    }
    double dot ( myVec v ) { ///Finds *this (dot) v
        double res = 0; for ( int i = 0; i < d; i++ ) res += val[i] * v.val[i];
        return res;
    }
    double length () { ///Finds length of current vector
        return sqrt ( this->dot( *this ) );
    }
    myVec unitVec () {
        return (*this).div ( length() ); /// v / ||v||
    }

    double angleBetween2D ( myVec b ) {
        double pol1 = atan2 ( val[1], val[0] );
        double pol2 = atan2 ( b.val[1], b.val[0] );
        if ( pol2 + eps < pol1 ) pol2 += 2 * PI;

        double x = pol2 - pol1;
        if ( x > PI + eps ) x = (2*PI) - x;

        ///For direction, use sign of cross2D
        return x;
    }

    ///Causes precision error. Use angleBetween2D when 2D.
    double angleBetween ( myVec b ) { ///Angle between two vectors
        double res = dot( b ) / ( length() * b.length() );
        if ( res > 1 ) res = 1; if ( res < -1 ) res = -1;
        return acos (res);
    }
    double polarAngle2D() { ///Angle from x-axis
        double res = atan2 ( val[1], val[0] );
        if ( res + eps < 0 ) res += 2 * PI;
        return res;
    }
    double cross2D ( myVec v ) { ///Cross the two values. Only for 2D. Z compo 0.
        return val[0]*v.val[1] - val[1]*v.val[0];
    }

    ///Provided, a comes before b. Otherwise, need to swap
    bool between ( myVec a, myVec b ) {
        if ( val[0] + eps < a.val[0] || val[0] > b.val[0] + eps ) return false;
        if ( val[1] + eps < a.val[1] || val[1] > b.val[1] + eps ) return false;
        return true;
    }
};

double triangleArea ( myVec a, myVec b, myVec c ) {
    double area = a.val[0] * b.val[1] + b.val[0] * c.val[1] + c.val[0] * a.val[1];
    area -= b.val[0] * a.val[1] + c.val[0] * b.val[1] + a.val[0] * c.val[1];
    area /= 2;
    return area;
}

struct myLine {
    myVec a, b; ///a is displacement, b is direction.
    ///Builds a line from two points
    myLine lineFromPoints ( myVec x, myVec y ) {
        myLine m;m.a = x; m.b = y.sub ( x );
        return m;
    }
    ///Line of the form Ax + By + C = 0
    myLine lineFromABC ( double A, double B, double C ) {
        if ( fabs (A) <= eps && fabs(B) <= eps ) {
            assert(false);
            myLine somethingIsWrong;
            return somethingIsWrong;
        }
        else if ( fabs(B) < eps ) { ///Vertical Line
            double x = -C / A;
            myVec p1;
            p1.val[0] = x; p1.val[1] = 0;
            myVec p2;
            p2.val[0] = x; p2.val[1] = 1;

            return lineFromPoints(p1, p2);
        }else {
            ///When x = 0
            double y = -C / B;
            myVec p1;
            p1.val[0] = 0; p1.val[1] = y;
            ///when x = 1
            y = ( -C - A ) / B;
            myVec p2;
            p2.val[0] = 1; p2.val[1] = y;

            return lineFromPoints(p1, p2);
        }
    }
    ///Finds point on line, given t.
    myVec atPos ( double t ) {
        return a.add ( b.mul ( t ) ); /// a + tb;
    }
    double lineToPointDistance ( myVec p, double &t ) {
        p = p.sub ( a ); ///Take it to origin
        t = b.dot ( p ) / ( b.length() * b.length() ); ///point of intersection
        myVec x = b.mul ( t ); ///tb
        return ( p.sub(x).length() ); ///xp length()
    }
    double segmentToPointDistance ( myVec p, double &t ) {
        p = p.sub ( a ); ///Take it to origin
        t = b.dot ( p ) / ( b.length() * b.length() );
        if ( t + eps < 0 || t > 1 + eps ) { ///Not on segment
            return min ( p.length(), p.sub(b).length() );
        }
        myVec x = b.mul ( t ); ///tb
        return ( p.sub(x).length() ); ///xp length()
    }
     bool overlapParallel ( myLine l ) {
            double p, q, r, s;
            if ( b.val[0] == 0 ) {
                p = a.val[1]; q = atPos(1).val[1]; r = l.a.val[1]; s = l.atPos ( 1 ).val[1];
                if ( min ( r, s ) > max ( p, q ) ) return false;
                if ( max ( r, s ) < min ( p, q ) ) return false;
                return true;
            }
            else {
                p = a.val[0]; q = atPos(1).val[0]; r = l.a.val[0]; s = l.atPos ( 1 ).val[0];
                if ( min ( r, s ) > max ( p, q ) ) return false;
                if ( max ( r, s ) < min ( p, q ) ) return false;
                return true;
            }
    }
    char lineAndLineIntersection2D ( myLine l, double &t, double &s ) {
        if ( b.cross2D ( l.b) == 0 ) {
            if ( l.a.sub(a).cross2D(l.b) == 0 ) {
                if ( overlapParallel ( l ) ) return 'o'; ///overlaps
                else return 'p'; ///parallel
            }
                else return 'd'; ///disjoint and parallel
        }
        myVec w = a.sub ( l.a );
        myVec p = l.b.perp2D(), z = b.perp2D();
        t = -(w.dot(p))/p.dot(b); ///for current line
        s = w.dot(z)/z.dot(l.b); ///for line l
        return 'i';
    }
    double lineAndLineDistance2D ( myLine l ) {
        double t, s; ///First check if the intersect
        char r = lineAndLineIntersection2D ( l, t, s );
        if ( r == 'i' ) return 0; ///Intersects. 0 distance.
        ///Parallel Lines
        return lineToPointDistance ( l.a, t );
    }
    double lineAndSegmentDistance2D ( myLine l ) {
        double t, s;
        char r = lineAndLineIntersection2D ( l, t, s );
        if ( r == 'i' && s + eps > 0 && s < 1 + eps ) {
                return 0; ///Valid intersection
        }
        double res = lineToPointDistance ( l.a, t );
        res = min ( res, lineToPointDistance ( l.a.add(l.b), t ) );
        return res;
    }
    double segmentAndSegmentDistance2D ( myLine l ) {
        double t, s;
        char r = lineAndLineIntersection2D ( l, t, s );
        if ( r =='i' && t+eps > 0 && t < 1 + eps && s + eps > 0 && s < 1 + eps ) {
                return 0; ///Valid intersection
        }
        double res = segmentToPointDistance ( l.a, t );
        res = min ( res, segmentToPointDistance ( l.a.add(l.b), t ) );
        res = min ( res, l.segmentToPointDistance ( a, t ) );
        res = min ( res, l.segmentToPointDistance ( a.add ( b ), t ) );
        return res;
    }
    myLine reflect ( myVec p, myVec norm ) {
        myVec ap = p.sub ( a ); ///Starting to Point of Reflection
        norm = norm.unitVec();

        double d = fabs ( ap.dot ( norm ) );

        myVec m = p.add ( norm.mul ( d ) );
        myVec h = m.sub ( a ).mul ( 2 );
        m = a.add ( h );

        myLine ray = ray.lineFromPoints ( p, m );
        return ray;
    }
};
myVec ara[5005];
int answer[12];
int main()
{
   int n = 0;
   double a,b,c;
   while(cin >> ara[n].val[0] >> ara[n].val[1] >> ara[n].val[2])
   {
      if(ara[n].val[0] == 0 and  ara[n].val[1]== 0 and ara[n].val[2]==0)break;
      n++;
   }
   for(int i = 0;i < n;i++){
      int D = 1e9;
      for(int j = 0; j < n;j++){
         if(i == j)continue;
         myVec P;
         for(int k = 0;k < 3;k++){
            P.val[k] = ara[i].val[k] - ara[j].val[k];
         }
         D = min(D,(int)P.length());
      }
      answer[D]++;
   }
   for(int i = 0;i < 10;i++){
      printf("%4d",answer[i]);
   }
   printf("\n");

}
