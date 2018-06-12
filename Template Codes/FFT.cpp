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

struct complx{
    long double real, img;

    inline complx(){
        real = img = 0.0;
    }

    inline complx(long double x){
        real = x, img = 0.0;
    }

    inline complx(long double x, long double y){
        real = x, img = y;
    }

    inline void operator += (complx &other){
        real += other.real, img += other.img;
    }

    inline void operator -= (complx &other){
        real -= other.real, img -= other.img;
    }

    inline complx operator + (complx &other){
        return complx(real + other.real, img + other.img);
    }

    inline complx operator - (complx &other){
        return complx(real - other.real, img - other.img);
    }

    inline complx operator * (complx& other){
        return complx((real * other.real) - (img * other.img), (real * other.img) + (img * other.real));
    }
};
;

void FFT(vector <complx> &ar, int n, int inv){
    int i, j, l, len, len2;
    const long double p = 4.0 * inv * acos(0.0);

    for (i = 1, j = 0; i < n; i++){
        for (l = n >> 1; j >= l; l >>= 1) j -= l;
        j += l;
        if (i < j) swap(ar[i], ar[j]);
    }

    for(len = 2; len <= n; len <<= 1) {
        long double ang = 2 * PI / len * inv;
        complx wlen(cos(ang), sin(ang));
        for(i = 0; i < n; i += len) {
            complx w(1);
            for(j = 0; j < len / 2; j++) {
                complx u = ar[i + j];
                complx v = ar[i + j + len / 2] * w;
                ar[i + j] = u + v;
                ar[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }

    if (inv == -1){
        long double tmp = 1.0 / n;
        for (i = 0; i < n; i++) ar[i].real *= tmp;
    }
}


vector <complx> Mul(const vector <complx> &x, const vector <complx> &y) {
    int n = 1;
    while(n <= x.size() + y.size()) n = n * 2;
    vector <complx> A(n), B(n);
    REP(i, x.size()) A[i] = x[i];
    REP(i, y.size()) B[i] = y[i];
    FFT(A, n, 1);
    FFT(B, n, 1);
    REP(i, n) A[i] = A[i] * B[i];
    FFT(A, n, -1);
    return A;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        vector<complx>v1,v2;

        int sign = 0;
        if(a[0] == '-'){
            sign = 1 - sign;
            a.erase(a.begin());
        }
        if(b[0] == '-'){
            sign = 1 - sign;
            b.erase(b.begin());
        }
        for(int i = 0;i < a.size();i++){
            int d = a[i] - '0';
            v1.push_back(complx(d));
        }
        for(int i = 0;i < b.size();i++){
            int d = b[i] - '0';
            v2.push_back(complx(d));
        }

        REV(v1); REV(v2);
        vector<complx>v = Mul(v1,v2);

        int carry = 0;
        vector<int>answer;
        for(int i = 0;i < v.size();i++){
            int temp = round(v[i].real);
            temp += carry;
            answer.push_back(temp % 10);
            carry = temp/10;
        }
        while(answer.size() > 1 and answer.back() == 0)answer.pop_back();
        REV(answer);

        for(int i : answer)cout << i;
        cout << "\n";

    }
}
