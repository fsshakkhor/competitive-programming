#include <bits/stdc++.h>
#define SQR(a) ((a)*(a))
using namespace std;
#define LL long long

const LL inf = (LL)1e18;

struct point {
        LL x, y;
        int id;
        point() {}
        point (LL a, LL b) : x(a), y(b) {}
};

LL dist(point p1,point p2)
{
    return (SQR(p1.x - p2.x) + SQR(p1.y - p2.y));
}
vector<point>vp;
LL closest(int L, int R ) {
        if( L == R ) return inf;
        if( L + 1 == R ) return dist( vp[L], vp[R] );
        int mid = ( L + R ) / 2;
        LL d = min( closest( L, mid ), closest( mid + 1, R ) );
        vector < int > br;
        for( int i=L; i<=R; i++ ) {
                if( SQR( vp[mid].x - vp[i].x ) <= d ) br.push_back( i );
        }
        sort( br.begin(), br.end(), []( const int& a, const int& b ) -> bool {
                return vp[a].y < vp[b].y;
        } );
        for( int i=0; i<(int)(br.size()); i++ ) {
                for( int j=i+1; j<(int)(br.size()) && j - i <= 7; j++ ) {
                        d = min( d, dist( vp[br[i]], vp[br[j]] ) );
                }
        }
        return d;
}

const LL N = 100005;
LL n,ara[N],cum[N];
int main()
{
    cin >> n;
    for(LL i = 0;i < n;i++)cin >> ara[i];
    LL s = 0;

    for(LL i = 0;i < n;i++)s = s + ara[i],cum[i] = s;
    for(LL i = 0;i < n;i++)vp.push_back({i,cum[i]});
    LL ans = closest(0,n - 1);
    cout << ans << "\n";
}




