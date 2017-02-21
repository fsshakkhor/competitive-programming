#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int dp[100000005];

int main()
{
    int i,j;
    while( scanf ("%d %d", &i, &j) != EOF )
    {
        int temp_i=i;
        int temp_j=j;

        if(i>j)swap(i,j);

        int len,maxlen=0;

        while(i<=j)
        {
            unsigned int n=i;
            len=1;


                int store=n;
                while(n!=1)
                {
                    if(n<=100000000)if(dp[n]!=0)
                    {
                        len+= dp[n]-1;
                        break;
                    }
                    if(n % 2==0)n = n >> 1;
                    else n = 3*n+1;
                    len++;

                }
                dp[store]=len;
                maxlen = max(maxlen,len);
            i++;
        }

         printf ("%d %d %d\n", temp_i, temp_j, maxlen);
    }



    return 0;
}
