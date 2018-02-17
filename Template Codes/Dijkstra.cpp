#include<bits/stdc++.h>

using namespace std;

struct point{
    int name,val;
    bool operator<(const point &a)const{
        return a.val<val;
    }
};
#define mx 1002
priority_queue<point> Q;
int dis[mx+5],cost[mx+5][mx+5];
vector<int>G[mx+5];

void DJ(point node){
    int now = node.name;
    if(node.val != dis[now])return;
    for(int i=0;i<G[now].size();i++){
        int x = G[now][i];

        if(dis[now]+cost[now][x]<dis[x]) ///Condition
        {
            dis[x]=dis[now]+cost[now][x];
            point get;
            get.name=x;
            get.val=dis[x];
            Q.push(get);
        }
    }
}

int main(){
        ///Must Initialize vector,dis[] array and cost[][] array
        ///Take Input
        dis[start]=0;
        point get;
        get.name=start;
        get.val=0;
        Q.push(get);
        while(not Q.empty())
        {
            point temp=Q.top();
            Q.pop();
            DJ(temp);
        }            ///Print Distance
}
