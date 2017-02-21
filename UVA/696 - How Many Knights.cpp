#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);

	int m,n,counter;

    while(scanf("%d %d", &m, &n))
	{
        if(m==0 && n==0)break;

		if(n==1)counter=m;
		else if(m==1)counter=n;
		else if(n==2)
        {
            int div = m/4;
            counter=div*4;

            if(m%4==1)counter+=2;
            else if(m%4>1)counter+=4;
        }
        else if(m==2)
        {
            int div = n/4;
            counter=div*4;

            if(n%4==1)counter+=2;
            else if(n%4>1)counter+=4;
        }
		else
        {
            counter = (m*n+1)/2;
        }
		printf("%d knights may be placed on a %d row %d column board.\n",counter,m,n);
	}

	return 0;
}
