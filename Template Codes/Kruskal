#include<bits/stdc++.h>

using namespace std;

struct edge{
    int u,v,w;
    bool operator < ( const edge &p ) const {
        return w < p.w;
    }
};
int pr[MAX];
vector<edge>e;

int find(int r){
   return (pr[r]==r) ? r : pr[r]=find(pr[r]);
}

int mst(int n){

    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++)pr[i]=i; ///Set Parent

    int count=0,s=0;
    for(int i=0;i<(int)e.size();i++){

        int u=find(e[i].u);
        int v=find(e[i].v);

        if(u!=v){
            pr[u]=v;
            count++;    ///Counts the number of edges
            s+=e[i].w;  ///Counts the sum of length of edges
            if(count==n-1) break;   ///When tree is formed,it breaks
        }
    }
    return s;
}
