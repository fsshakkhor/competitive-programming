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

const LL LLINF = 9000000000000000000;


template <class T>
struct seq {
	T val; int size_, priority;
	seq<T> *l = nullptr, *r = nullptr, *p = nullptr;
	seq(T _v) : val(_v), size_(1) { priority = rand(); }

	static int size(seq<T> *c) { return c == nullptr ? 0 : c->size_; }
	seq<T> *update() {
		size_ = 1;
		if(l != nullptr) l->p = this, size_ += l->size_;
		if(r != nullptr) r->p = this, size_ += r->size_;
		return this;
	}
	int index() {
		int ind = size(this->l);
		seq<T> *c = this;
		while(c->p != nullptr) {
			if(c->p->l != c) ind += 1 + size(c->p->l);
			c = c->p;
		}
		return ind;
	}
	seq<T> *root() { return this->p == nullptr ? this : p->root(); }
	seq<T> *min() { return this->l == nullptr ? this : l->min(); }
	seq<T> *max() { return this->r == nullptr ? this : r->max(); }
	seq<T> *next() { return this->r == nullptr ? this->p : this->r->min(); }
	seq<T> *prev() { return this->l == nullptr ? this->p : this->l->max(); }
};

// Note: Assumes both nodes are the roots of their sequences.
template <class T>
seq<T> *merge(seq<T> *A, seq<T> *B) {
	if(A == nullptr) return B;
	if(B == nullptr) return A;
	if(A->priority > B->priority) {
		A->r = merge(A->r, B);
		return A->update();
	} else {
		B->l = merge(A, B->l);
		return B->update();
	}
}

// Note: Assumes all nodes are the roots of their sequences.
template <class T, typename... Seqs>
seq<T> *merge(seq<T> *l, Seqs... seqs) {
	return merge(l, merge(seqs...));
}

// Split into [0, index) and [index, ..)
template <class T>
pair<seq<T> *, seq<T> *> split(seq<T> *A, int index) {
	if(A == nullptr) return {nullptr, nullptr};
	A->p = nullptr;
	if(index <= seq<T>::size(A->l)) {
		auto pr = split(A->l, index);
		A->l = pr.second;
		return {pr.first, A->update()};
	} else {
		auto pr = split(A->r, index - (1 + seq<T>::size(A->l)));
		A->r = pr.first;
		return {A->update(), pr.second};
	}
}

// return [0, x), [x, ..)
template <class T>
pair<seq<T> *, seq<T> *> split(seq<T> *A) {
	if (A == nullptr) return {nullptr, nullptr};
	seq<T> *B = A, *lr = A; A = A->l;
	if (A == nullptr) {
		while (lr->p != nullptr && lr->p->l == B) lr = B = lr->p;
		if (lr->p != nullptr) {
			lr = A = lr->p; lr->r = B->p = nullptr;
		}
	} else	A->p = lr->l = nullptr;
	while (lr->update()->p != nullptr) {
			if (lr->p->l == lr) {
				if (lr == A) swap(A->p, B->p), B->p->l = B;
				lr = B = B->p;
			} else {
				if (lr == B) swap(A->p, B->p), A->p->r = A;
				lr = A = A->p;
			}
	}
	return {A, B};
}

struct EulerTourTree {
	struct edge { int u, v; };
	vector<seq<edge>> vertices;
	vector<unordered_map<int, seq<edge>>> edges;
	EulerTourTree(int n) {
		vertices.reserve(n); edges.reserve(n);
		for (int i = 0; i < n; ++i) add_vertex();
	}

	// Create a new vertex.
	int add_vertex() {
		int id = (int)vertices.size();
		vertices.push_back(edge{id, id});
		edges.emplace_back();
		return id;
	}
	// Find root of the subtree containg this vertex.
	int root(int u) { return vertices[u].root()->min()->val.u; }
	bool connected(int u, int v) { return vertices[u].root()==vertices[v].root(); }
	int size(int u) { return (vertices[u].root()->size_ + 2) / 3; }
	// Make v the parent of u. Assumes u has no parent!
	void attach(int u, int v) {
		seq<edge> *i1, *i2;
		tie(i1, i2) = split(&vertices[v]);
		::merge(i1,
				&(edges[v].emplace(u, seq<edge>{edge{v, u}}).first)->second,
				vertices[u].root(),
				&(edges[u].emplace(v, seq<edge>{edge{u, v}}).first)->second,
				i2);
	}
	// Reroot the tree containing u at u.
	void reroot(int u) {
		seq<edge> *i1, *i2;
		tie(i1, i2) = split(&vertices[u]);
		merge(i2, i1);
	}
	// Links u and v.
	void link(int u, int v) { reroot(u); attach(u, v); }
	// Cut {u, v}. Assumes it exists!!
	void cut(int u, int v) {
		auto uv = edges[u].find(v), vu = edges[v].find(u);
		if (uv->second.index() > vu->second.index()) swap(u, v), swap(uv, vu);
		seq<edge> *i1, *i2;
		tie(i1, i2) = split(&uv->second); split(i2, 1);
		merge(i1, split(split(&vu->second).second, 1).second);
		edges[u].erase(uv); edges[v].erase(vu);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	EulerTourTree ett(n);
	while (q--) {
		string s; int a, b;
		cin >> s >> a >> b; --a; --b;
		if (s[0] == 'a') ett.link(a, b);
		if (s[0] == 'r') ett.cut(a, b);
		if (s[0] == 'c') cout << (ett.connected(a, b) ? "YES" : "NO") << '\n';
	}

	return 0;
}
