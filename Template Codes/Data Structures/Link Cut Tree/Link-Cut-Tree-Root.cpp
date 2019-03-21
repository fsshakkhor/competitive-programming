
#include<bits/stdc++.h>
using namespace std;
#define D(x)    cout << #x " = " <<(x) << endl
#define MAX     100000
typedef long long int LL;

struct Node{
    int sum, label, value;
    Node *p, *pp, *l, *r;
    Node(){
        p = pp = l = r = 0;
        sum = value = 0;
    }
};

void update(Node *x){
    x->sum = x->value;
    if(x->l) x->sum += x->l->sum;
    if(x->r) x->sum += x->r->sum;
}

void toggle(Node *x){
    x->value = 1 - x->value;
    x->sum = x->value;
    if(x->l) x->sum += x->l->sum;
    if(x->r) x->sum += x->r->sum;
}

void rotr(Node *x){
    Node *y, *z;
    y = x->p, z = y->p;
    if((y->l = x->r)) y->l->p = y;
    x->r = y, y->p = x;
    if((x->p = z)){
        if(y == z->l) z->l = x;
        else z->r = x;
    }
    x->pp = y->pp;
    y->pp = 0;
    update(y);
}

void rotl(Node *x){
    Node *y, *z;
    y = x->p, z = y->p;

    if((y->r = x->l)) y->r->p = y;
    x->l = y, y->p = x;
    if((x->p = z)){
        if(y == z->l) z->l = x;
        else z->r = x;
    }
    x->pp = y->pp;
    y-> pp = 0;
    update(y);
}

void splay(Node *x){
    Node *y, *z;
    while(x->p){
        y = x->p;
        if(y->p == 0){
            if(x == y->l) rotr(x);
            else rotl(x);
        }
        else{
            z = y->p;
            if(y == z->l){
                if(x == y->l) rotr(y), rotr(x);
                else rotl(x), rotr(x);
            }
            else{
                if(x == y->r) rotl(y), rotl(x);
                else rotr(x), rotl(x);
            }
        }
    }
    update(x);
}

Node *access(Node *x){
    splay(x);
    if(x->r){
        x->r->pp = x;
        x->r->p = 0;
        x->r = 0;
        update(x);
    }

    Node *last = x;
    while(x->pp){
        Node *y = x->pp;
        last = y;
        splay(y);
        if(y->r){
            y->r->pp = y;
            y->r->p = 0;
        }

        y->r = x;
        x->p = y;
        x->pp = 0;
        update(y);
        splay(x);
    }
    return last;
}

Node *root(Node *x){
    access(x);
    while(x->l) x = x->l;
    splay(x);
    return x;
}

void cut(Node *x){
    access(x);
    x->l->p = 0;
    x->l = 0;
    update(x);
}

void link(Node *x, Node *y){
    access(x);
    access(y);
    x->l = y;
    y->p = x;
    update(x);
}

Node *lca(Node *x, Node *y){
    access(x);
    return access(y);
}

int query(Node *x){
    access(x);
    return x->sum;
}

int get(Node *x, int k){
    int ls = (x->r)? x->r->sum : 0;
    if(ls >= k) return get(x->r, k);
    if(x->value && ls == k - 1) return x->label;
    return get(x->l, k - (x->value + ls));
}

class LinkCut{
public:
    Node *x;
    LinkCut(int n){
        x = new Node[n+5];
        for(int i = 1; i <= n; i++){
            x[i].label = i;
            update(&x[i]);
        }
    }

    void link(int u, int v){
        ::link(&x[u], &x[v]);
    }

    void cut(int u){
        ::cut(&x[u]);
    }

    int lca(int u, int v){
        return ::lca(&x[u], &x[v])->label;
    }

    int query(int u){
        return ::query(&x[u]);
    }

    void toggle(int u){
        access(&x[u]);
        ::toggle(&x[u]);
    }
    int root(int u){
        return ::root(&x[u])->label; 
    }

} *lctree;


int main()
{
    lctree = new LinkCut(10);
    lctree->link(1,2);
    lctree->link(2,3);
    lctree->link(4,3);

    lctree->link(5,6);
    lctree->link(7,5);

    cout << lctree->root(7) << endl;

    return 0;
}
