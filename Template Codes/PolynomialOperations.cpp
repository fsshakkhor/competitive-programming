#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 155;
const int MOD = 1e9 + 7;
 
struct polynomial {
  int deg;
  ll coeff[N];
 
  polynomial () {
    deg = 0;
    memset(coeff, 0, sizeof coeff);
  }
};
 
polynomial f, g;
 
ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  e %= (MOD - 1);
  ll r = 1; 
  while (e) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return r;
}
 
polynomial product (polynomial f, polynomial g) {
  polynomial h;
  h.deg = f.deg + g.deg;
 
  for (int i = 0; i <= f.deg; ++i)
    for (int j = 0; j <= g.deg; ++j)
      h.coeff[i + j] += f.coeff[i] * g.coeff[j], h.coeff[i + j] %= MOD;
 
  return h;
}
 
// Assuming deg f >= deg g
polynomial quotient (polynomial f, polynomial g) {
  polynomial q;
  q.deg = f.deg - g.deg;
 
  for (int i = q.deg; i >= 0; --i) {
    q.coeff[i] = (f.coeff[g.deg + i] * bigMod(g.coeff[g.deg], -1)) % MOD;
    for (int j = g.deg; j >= 0; --j) 
      f.coeff[i + j] -= q.coeff[i] * g.coeff[j], f.coeff[i + j] %= MOD;   
  }
 
  return q;
}
 
polynomial remainder (polynomial f, polynomial g) {
  if (f.deg < g.deg) return f;
 
  for (int i = f.deg - g.deg; i >= 0; --i) {
    ll c = (f.coeff[g.deg + i] * bigMod(g.coeff[g.deg], -1)) % MOD;
    for (int j = g.deg; j >= 0; --j) 
      f.coeff[i + j] -= c * g.coeff[j], f.coeff[i + j] %= MOD;   
  }
 
  f.deg = g.deg - 1;
  while (f.coeff[f.deg] == 0) --f.deg;
  f.deg = max(f.deg, 0);
  return f;
}
 
int n, tot;
 
// Euclidean Algorithm
polynomial gcd (polynomial f, polynomial g) {
  if (g.deg == 0 and g.coeff[0] == 0) return f;
  return ++tot, gcd(g, remainder(f, g));
}
 
int get (void) {
	return (rand() % 3) - 1;
}
 
void print (void) {
	assert(f.deg > g.deg);
	cout << f.deg << '\n';
	for (int i = 0; i <= f.deg; ++i) {
		cout << f.coeff[i] << " ";
	}
	cout << '\n';
	cout << g.deg << '\n';
	for (int i = 0; i <= g.deg; ++i) {
		cout << g.coeff[i] << " ";
	}
	cout << '\n';
}
 
int main() {
	srand(time(0));
	cin >> n;
	while (true) {
		f.deg = n, g.deg = n - 1;
		f.coeff[n] = g.coeff[n - 1] = 1;
		for (int i = 0; i < n; ++i) {
			f.coeff[i] = get();
		}
		for (int i = 0; i < n - 1; ++i) {
			g.coeff[i] = get();
		}
		tot = 0;
		gcd(f, g);
		if (tot == n) {
			print();
			return 0;
		}
	}
	assert(false);
	return 0;
}
