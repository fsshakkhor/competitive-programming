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


const int N = 200005;

map <string, int> id;
string query[N], s, comp[N];
int n, m, ptr, last[N], ans[N];
int ending[N];
int counter[N],starting[N];
struct AC {
  int N, P;
  vector<vector<int>> next;
  vector<int> link, out_link;
  vector<vector<int>> out;
  AC(): N(0), P(0) { node(); }
  int node() {
    next.emplace_back(26, 0);
    link.emplace_back(0);
    out_link.emplace_back(0);
    out.emplace_back(0);
    return N++;
  }
  int add_pattern(const string T) {
    int u = 0;
    for (auto c : T) {
      if (!next[u][c - 'a']) next[u][c - 'a'] = node();
      u = next[u][c - 'a'];
    }
    out[u].push_back(P);
    return P++;
  }
  void compute() {
    queue<int> q;
    for (q.push(0); !q.empty(); ) {
      int u = q.front(); q.pop();
      // automaton:
      for (int c = 0; c < 26; ++c) {
        int v = next[u][c];
        if (!v) next[u][c] = next[link[u]][c];
        else {
          link[v] = u ? next[link[u]][c] : 0;
          out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
          q.push(v);
        }
      }
    }
  }
  int advance(int u, char c) {

    while (u && !next[u][c - 'a']) u = link[u];
    u = next[u][c - 'a'];
    return u;
  }
  void match(const string S) {
    int u = 0;
    for (int i = 0; i < S.size(); ++i) {
      char c = S[i];
      u = advance(u, c);

      for (int v = u; v; v = out_link[v]) {
        for (auto p : out[v]) {
            ++ans[p];
            ending[i] += counter[p];
            starting[i - comp[p].size() + 1] += counter[p];
            last[p] = i;
        }
      }
    }
  }
} aho;



int main() {

  cin >> s;
  n = s.size();
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> query[i];
    if (id.find(query[i]) == id.end()) {
      comp[ptr] = query[i];
      id[query[i]] = ptr++;
      aho.add_pattern(query[i]);
    }
    counter[id[query[i]]]++;
  }

  aho.compute();
  memset(last, -1, sizeof last);
  aho.match(s);
  LL answer = 0;
//  for(int i = 0;i < n;i++){
//    cout << starting[i] << " ";
//  }
//  cout << endl;
  for(int i = 0;i < n - 1;i++){
    LL cnt = (LL)ending[i] * (LL)starting[i + 1];
    answer += cnt;
  }
  cout << answer << "\n";
  return 0;
}
