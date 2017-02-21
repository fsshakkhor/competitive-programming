#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int b1,g1,c1,b2,g2,c2,b3,g3,c3;
    while(scanf("%d %d %d %d %d %d %d %d %d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)!=EOF)
    {
        int ans1 = b2+b3+c1+c3+g1+g2;
        int ans2 = b2+b3+g1+g3+c1+c2;
        int ans3 = c2+c3+b1+b3+g1+g2;
        int ans4 = c2+c3+g1+g3+b1+b2;
        int ans5 = g2+g3+b1+b3+c1+c2;
        int ans6 = g2+g3+c1+c3+b1+b2;

        int ans=min(ans1,ans2);
        ans = min(ans,ans3);
        ans = min(ans,ans4);
        ans = min(ans,ans5);
        ans = min(ans,ans6);

        if(ans==ans1)printf("BCG %d\n",ans);
        else if(ans==ans2)printf("BGC %d\n",ans);
        else if(ans==ans3)printf("CBG %d\n",ans);
        else if(ans==ans4)printf("CGB %d\n",ans);
        else if(ans==ans5)printf("GBC %d\n",ans);
        else if(ans==ans6)printf("GCB %d\n",ans);
    }
    return 0;
}
