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

class Graph
{
public:
    struct Edge
    {
        int v,flow,cap,rev;
    };

    int V;
    int *level;
    vector<Edge>*adj;

    Graph(int V)
    {
        this->V = V;
        level = new int[V];
        adj = new vector<Edge>[V];
    }

    void addEdge(int u,int v,int c)
    {
        Edge a{v,0,c,adj[v].size()};
        Edge b{u,0,0,adj[u].size()};

        adj[u].pb(a);
        adj[v].pb(b);
    }

    bool Bfs(int s,int t)
    {
        REP(i,V)level[i]=-1;
        level[s]=0;

        queue<int>Q;
        Q.push(s);

        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for(auto it = adj[u].begin(); it!=adj[u].end(); it++)
            {
                Edge &e = *it;
                if(level[e.v]==-1 and e.flow<e.cap)
                {
                    level[e.v] = level[u] + 1;
                    Q.push(e.v);
                }
            }
        }
        return level[t]!=-1;
    }

    int sendFlow(int u,int flow,int t,int start[])
    {
        if(u==t)return flow;

        for( ; start[u] < adj[u].size() ; start[u]++)
        {
            Edge &e = adj[u][start[u]];
            if(level[e.v]==level[u]+1 and e.flow < e.cap)
            {
                int cur =  min(flow,e.cap - e.flow);

                int temp = sendFlow(e.v,cur,t,start);

                if(temp>0)
                {
                    e.flow += temp;

                    adj[e.v][e.rev].flow-=temp;
                    return temp;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s,int t)
    {
        if(s==t)return -1;
        int total = 0;

        while(Bfs(s,t))
        {
            int *start = new int[V+1];
            while(int flow = sendFlow(s,INT_MAX,t,start))
                total+=flow;

        }
        return total;
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 1, 16 );
    g.addEdge(0, 2, 13 );
    g.addEdge(1, 2, 10 );
    g.addEdge(1, 3, 12 );
    g.addEdge(2, 1, 4 );
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9 );
    g.addEdge(3, 5, 20 );
    g.addEdge(4, 3, 7 );
    g.addEdge(4, 5, 4);

    cout << "Maximum flow " << g.maxFlow(0, 5);
}
