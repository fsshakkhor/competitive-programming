#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
#define inf 0x3f3f3f3f
#define vi vector <int>
#define all(a) a.begin(), a.end()
#define Unique(a) sort(all(a)), a.erase(unique(all(a)), a.end())

struct data {
    int l, r, c;
    data() {
        l = r = c = 0;
    }
    data(int a, int b, int d) {
        l = a;
        r = b;
        c = d;
    }
}T[N * 20];

int n, in[N], Root[N], id, qr;

int update(int pr, int b, int e, int pos) {
    int node = ++id;
    T[node] = T[pr];
    if(b == e) {
        T[node].c++;
        return node;
    }
    int mid = b + e >> 1;
    if(pos <= mid) T[node].l = update(T[node].l, b, mid, pos);
    else T[node].r = update(T[node].r, mid + 1, e, pos);
    T[node].c = T[ T[node].l ].c + T[ T[node].r ].c;
    return node;
}

int query(int pr, int cr, int b, int e, int nd) {
    if(b == e) return b;
    int have = T[ T[cr].l ].c - T[ T[pr].l ].c;
//    cout << "from : " << b << " " << e << " , " << T[cr].c - T[pr].c << '\n';
    int mid = b + e >> 1;
    if(nd <= have) return query(T[pr].l, T[cr].l, b, mid, nd);
    else return query(T[pr].r, T[cr].r, mid + 1, e, nd - have);
}

int main()
{
    scanf("%d %d", &n, &qr);
    for(int i = 1; i <= n; i++) scanf("%d", &in[i]);
    vi cmp; cmp.push_back(-inf);
    for(int i = 1; i <= n; i++) cmp.push_back(in[i]); Unique(cmp);
    for(int i = 1; i <= n; i++) in[i] = lower_bound(all(cmp), in[i]) - cmp.begin();
    Root[0] = ++id;
    for(int i = 1; i <= n; i++) Root[i] = update(Root[i - 1], 1, cmp.size(), in[i]);
    while(qr--) {
        int l, r, k; scanf("%d %d %d", &l, &r, &k);
        int p = query(Root[l - 1], Root[r], 1, cmp.size(), k);
        int val = cmp[p];
//        cerr << p << '\n';
        printf("%d\n", val);
    }
    return 0;
