#include<bits/stdc++.h>
 
using namespace std;
const int N = 105;
int cost[N][N],cap[N][N],ara[N][N];
int pr[N],dis[N];
 
vector<pair<int,int> >e;
void addEdge(int u,int v,int w)
{
   e.push_back(make_pair(u,v));
   e.push_back(make_pair(v,u));
   cap[u][v] += 1;
   cost[u][v] = 1000000-w;
   cost[v][u] = 1000000+w;
}
 
int bel(int s,int t)
{
   for(int i = 0;i<N;i++)dis[i] = 1e9;
   dis[s] = 0;
   pr[s] = 0;
   for(int i = 0;i<N;i++){
      for(int j = 0;j<e.size();j++){
         int u = e[j].first;
         int v = e[j].second;
         if(cap[u][v] == 0)continue;
         if(dis[u] + cost[u][v] < dis[v]){
            dis[v] = dis[u] + cost[u][v];
            pr[v] = u;
         }
      }
   }
   if(dis[t] == 1e9)return 0;
   else return 1;
 
}
 
void init()
{
   memset(cost,0,sizeof(cost));
   memset(cap,0,sizeof(cap));
   memset(pr,0,sizeof(pr));
   memset(dis,0,sizeof(dis));
   memset(ara,0,sizeof(ara));
   e.clear();
}
int main()
{
   int t,cases=0;
   cin >> t;
   while(t--)
   {
      init();
      int n;
      cin >> n;
      for(int i = 1;i<=n;i++){
         for(int j = 1;j<=n;j++){
            cin >> ara[i][j];
            addEdge(i , n + j, ara[i][j]);
         }
      }
      for(int i = 1;i<=n;i++){
         addEdge(0,i,0);
         addEdge(n + i,2*n + 1,0);
      }
      int flow = 0,answer = 0;
      while(bel(0,2*n+1))
      {
         for(int v = 2*n + 1;v!=0;v=pr[v]){
            int u = pr[v];
            cap[u][v]-=1;
            cap[v][u]-=1;
            answer += cost[u][v];
         }
         flow++;
      }
      cout << "Case " << ++cases << ": " << (n*3*1000000 - answer) << "\n";
   }
}
 
