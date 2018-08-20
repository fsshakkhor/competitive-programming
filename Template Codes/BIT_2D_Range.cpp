#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
long long int BIT[2][2][1025][1025];

void update(int x,int y,long long int value){
    int xx=x;
    while(xx<=n){
        int yy=y;
        while(yy<=n){
            BIT[x%2][y%2][xx][yy]^=value;
            yy+=(yy&-yy);
        }
        xx+=(xx&-xx);
    }
}

long long int sum(int x,int y){
    long long int ans=0;
    int xx=x;
    while(xx!=0){
        int yy=y;
        while(yy!=0){
            ans^=BIT[x%2][y%2][xx][yy];
            yy-=(yy&-yy);
        }
        xx-=(xx&-xx);
    }
    return ans;
}

int main(){
    int p,q;
    int a,b,c,d;
    long long int val;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf("%d",&p);
        if(p==1){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            long long int ans=sum(c,d)^sum(a-1,b-1)^sum(c,b-1)^sum(a-1,d);
            printf("%I64d\n",ans);
        }
        else{
            scanf("%d %d %d %d %I64d",&a,&b,&c,&d,&val);
            update(a,b,val);
            update(a,d+1,val);
            update(c+1,b,val);
            update(c+1,d+1,val);
        }
    }
}
