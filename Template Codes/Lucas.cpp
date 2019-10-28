#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int mod = 999377; 
int f[mod], inv[mod];

int nCr(int n, int r) {
    if(r > n) return 0;
    int ret = (ll) f[n] * inv[r] % mod;
    return (ll) ret * inv[n - r] % mod; 
}

int lucas(ll n, ll r) {
    if(!r) return 1; 
    return (ll) lucas(n / mod, r / mod) * nCr(n % mod, r % mod) % mod;
}

inline int Pow(int a, int p) {
    int ret = 1; while(p) {
        if(p & 1) ret = (ll) ret * a % mod;
        a = (ll) a * a % mod;
        p >>= 1;
    } return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    f[0] = 1; 
    for(int i = 1; i < mod; ++i) {
        f[i] = (ll) i * f[i - 1] % mod; 
    }    

    inv[mod - 2] = Pow(f[mod - 2], mod - 2); 
    for(int i = mod - 3; i >= 0; --i) {
        inv[i] = (ll) inv[i + 1] * (i + 1) % mod;
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t, co = 0; cin >> t; while(t--) {
        ll n; cin >> n;
        cout << "Case " << ++co << ": " << lucas(2 * n, n) << endl;
    }    
}
