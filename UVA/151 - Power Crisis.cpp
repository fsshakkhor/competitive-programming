#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    unsigned short int n;

    while(scanf("%hu",&n))
    {
        if(n==0)break;

            int i,ans;
            for(i=1;i<n;i++)
            {
                int ara[n],t=1,f=0,x,p=0;
                for(x=0;x<n;x++)ara[x]=1;
                ara[0]=0;

                while(ara[12]==1)
                {

                    while(f<i)
                    {
                        p++;
                        p = p % n;
                        if(ara[p]==1)f++;

                    }
                    f=0;
                    if(ara[p]==1){ara[p]=0;t++;}
                }
                if(t==n)
                {
                    ans = i;
                    break;
                }

            }
            cout << ans <<endl;
    }
    return 0;
}
