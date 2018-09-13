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
#define MAXD 4
#define eps 1e-9

double cosineRule3Side ( double a, double b, double c ) {
    double res = (SQ(a)+SQ(b)-SQ(c)) / (2*a*b);
    if ( res < -1 ) res = -1; if ( res > 1 ) res = 1;
    return acos ( res );
}

struct myVec {
    int d; //Dimension
    double val[MAXD];//Contains value of each component

    myVec add ( myVec b ) {
        myVec res; FOR(i,0,d) res.val[i] = val[i] + b.val[i];return res;
    }
    myVec sub ( myVec b ) {
        myVec res; FOR(i,0,d) res.val[i] = val[i] - b.val[i];return res;
    }
    myVec mul ( double t ) {
        myVec res; FOR(i,0,d)res.val[i] = val[i] * t;return res;
    }
    myVec div ( double t ) {
        myVec res; FOR(i,0,d) res.val[i] = val[i] / t;return res;
    }
    bool operator == ( myVec b ) {
        FOR(i,0,d) if ( fabs ( val[i] - b.val[i] ) > eps ) return false; return true;
    }
    myVec perp2D() {
        myVec res = (*this);
        swap ( res.val[0], res.val[1] );
        res.val[0] *= -1;
        return res;
    }
    double dot ( myVec v ) { //Finds *this (dot) v
        double res = 0; for ( int i = 0; i < d; i++ ) res += val[i] * v.val[i];
        return res;
    }
    double length () { //Finds length of current vector
        return sqrt ( this->dot( *this ) );
    }
    myVec unitVec () {
        return (*this).div ( length() ); // v / ||v||
    }
    double angleBetween ( myVec b ) { //Angle between two vectors
        double res = dot( b ) / ( length() * b.length() );
        if ( res > 1 ) res = 1; if ( res < -1 ) res = -1;
        return acos (res);
    }
    double polarAngle2D() { //Angle from x-axis
        double res = atan2 ( val[1], val[0] );
        if ( res + eps < 0 ) res += 2 * pi;
        return res;
    }
    double cross2D ( myVec v ) { //Cross the two values. Only for 2D. Z compo 0.
        return val[0]*v.val[1] - val[1]*v.val[0];
    }
};

struct myLine {
    myVec a, b; //a is displacement, b is direction.
    //Builds a line from two points
    myLine lineFromPoints ( myVec x, myVec y ) {
        myLine m;m.a = x; m.b = y.sub ( x );
        return m;
    }
    //Finds point on line, given t.
    myVec atPos ( double t ) {
        return a.add ( b.mul ( t ) ); // a + tb;
    }
    double lineToPointDistance ( myVec p, double t ) {
        p = p.sub ( a ); //Take it to origin
        t = b.dot ( p ) / ( b.length() * b.length() ); //point of intersection
        myVec x = b.mul ( t ); //tb
        return ( p.sub(x).length() ); //xp length()
    }
    double segmentToPointDistance ( myVec p, double &t ) {
        p = p.sub ( a ); //Take it to origin
        t = b.dot ( p ) / ( b.length() * b.length() );
        if ( t + eps < 0 || t > 1 + eps ) { //Not on segment
            return min ( p.length(), p.sub(b).length() );
        }
        myVec x = b.mul ( t ); //tb
        return ( p.sub(x).length() ); //xp length()
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
                if ( overlapParallel ( l ) ) return 'o'; //overlaps
                else return 'p'; //parallel
            }
                else return 'd'; //disjoint and parallel
        }
        myVec w = a.sub ( l.a );
        myVec p = l.b.perp2D(), z = b.perp2D();
        t = -(w.dot(p))/p.dot(b); //for current line
        s = w.dot(z)/z.dot(l.b); //for line l
        return 'i';
    }
    double lineAndLineDistance2D ( myLine l ) {
        double t, s; //First check if the intersect
        char r = lineAndLineIntersection2D ( l, t, s );
        if ( r == 'i' ) return 0; //Intersects. 0 distance.
        //Parallel Lines
        return lineToPointDistance ( l.a, t );
    }
    double lineAndSegmentDistance2D ( myLine l ) {
        double t, s;
        char r = lineAndLineIntersection2D ( l, t, s );
        if ( r == 'i' && s + eps > 0 && s < 1 + eps ) {
                return 0; //Valid intersection
        }
        double res = lineToPointDistance ( l.a, t );
        res = min ( res, lineToPointDistance ( l.a.add(l.b), t ) );
        return res;
    }
    double segmentAndSegmentDistance2D ( myLine l ) {
        double t, s;
        char r = lineAndLineIntersection2D ( l, t, s );
        if ( r =='i' && t+eps > 0 && t < 1 + eps && s + eps > 0 && s < 1 + eps ) {
                return 0; //Valid intersection
        }
        double res = segmentToPointDistance ( l.a, t );
        res = min ( res, segmentToPointDistance ( l.a.add(l.b), t ) );
        res = min ( res, l.segmentToPointDistance ( a, t ) );
        res = min ( res, l.segmentToPointDistance ( a.add ( b ), t ) );
        return res;
    }
    myLine reflect ( myVec p, myVec norm ) {
        myVec ap = p.sub ( a ); //Starting to Point of Reflection
        norm = norm.unitVec();

        double d = fabs ( ap.dot ( norm ) );

        myVec m = p.add ( norm.mul ( d ) );
        myVec h = m.sub ( a ).mul ( 2 );
        m = a.add ( h );

        myLine ray = ray.lineFromPoints ( p, m );
        return ray;
    }
};

struct myCir {
    myVec a;
    double r;
    myVec atPos ( double t ) {
        myVec res;
        res.val[0] = a.val[0] + r * cos ( t );
        res.val[1] = a.val[1] + r * sin ( t );
        return res;
    }
    char circleAndLineIntersection2D ( myLine l, double &t1, double &t2 ) {
        double t3;
        double d = l.lineToPointDistance ( a, t3 );
        if ( d > r + eps ) return 'd';
        if ( fabs ( d - r ) <= eps ) return 't';

        myVec m = l.atPos ( t3 );
        myVec am = m.sub ( a );

        //Need to handle when line passes through center

        double x = am.polarAngle2D();
        double temp = d / r; if ( temp > 1 ) temp = 1; if ( temp < -1 ) temp = -1;
        double theta = pi / 2 - asin ( temp ); //Using sin law find internal angle.

        t1 = x + theta;
        t2 = x - theta;
        return 'i';
    }
    char sphereAndLineIntersect ( myLine l, double &t1, double &t2 ) {
        double tp = 0;
        double d = l.lineToPointDistance ( a, tp );
        if ( d > r + eps ) return 'd';
        if ( fabs ( d - r ) < eps ) {
            t1 = tp;
            return 't';
        }
        double chord = sqrt ( r * r - d * d );
        t1 = tp - chord / l.b.length();
        t2 = tp + chord / l.b.length();
        return 'i';
    }
     char circleAndCircleIntersection2D ( myCir c2, double &t1, double &t2 ) {
        myVec d = c2.a.sub ( a );
        if ( d.length() > r + c2.r + eps ) return 'd'; //Case 1
        if ( d.length() + c2.r + eps < r ) return 'd'; //Case 2
        if ( a == c2.a && fabs ( r - c2.r ) <= eps ) {
            if ( r == 0 ) {
                t1 = 0;
                return 't'; //Case 7
            }
            return 's'; //Case 6
        }
        if ( fabs ( d.length() - r - c2.r ) <= eps ||
             fabs ( d.length() + c2.r - r ) <= eps ) {
            t1 = d.polarAngle2D();
            return 't'; //Case 3 and 4
        }
        double theta = cosineRule3Side ( r, d.length(), c2.r );
        double m = d.polarAngle2D ();
        t1 = m - theta;
        t2 = m + theta;
        return 'i'; //Case 5
    }
    int circleToCircleTangentLine (myCir c2,myLine &l1,myLine &l2,myLine &l3,myLine &l4){
    //First circle must be smaller or equal to second circle
        if (r>c2.r + eps ) return c2.circleToCircleTangentLine ( *this, l1, l2, l3, l4 );

        myVec oo = c2.a.sub ( a );
        double d = oo.length();

        if ( fabs ( d ) < eps && fabs ( r - c2.r ) < eps ) //Infinite tangents
            return -1;
        if ( d + r + eps < c2.r ) //No tangents
            return 0;

          double base = oo.polarAngle2D();

        if ( fabs ( d + r - c2.r ) < eps ) { //Contains Circle
            l1 = l1.lineFromPoints ( atPos ( base + pi ), atPos ( base + pi ) );
            return 1;
        }

        double ang = pi - acos ( (c2.r - r ) / d );
        l1 = l1.lineFromPoints ( atPos ( base + ang ), c2.atPos ( base + ang ) );
        l2 = l2.lineFromPoints ( atPos ( base - ang ), c2.atPos ( base - ang ) );

        if ( d + eps < r + c2.r ) return 2; //Circle intersects

        if ( fabs ( d - r - c2.r ) < eps ) { //Circle tangent
            l3 = l3.lineFromPoints ( atPos ( base ), atPos ( base ) );
            return 3;
        }

        //Disjoint Circle
        ang = acos ( ( c2.r + r ) / d );
        l3 = l3.lineFromPoints ( atPos ( base + ang ), c2.atPos ( base + ang + pi ) );
        l4 = l4.lineFromPoints ( atPos ( base - ang ), c2.atPos ( base - ang + pi ) );

        return 4;
    }
};


bool collinear ( myVec a, myVec b, myVec c ) {
    myVec ab = b.sub(a), ac = c.sub(a);
    double d = fabs ( ab.dot(ac) );
    if ( fabs ( d - ab.length() * ac.length() ) <= eps ) return true;
    return false;
}
