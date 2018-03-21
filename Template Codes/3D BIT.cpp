#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long matrix[101][101][101];


void update(long long n,long long x,long long y,long long z,long long  val) {
    long long y1,x1;

    while(z <= n) {
        x1 = x;
        while(x1 <= n) {
            y1 = y;
            while(y1 <= n) {
                matrix[x1][y1][z] += val;
                y1 += (y1 & -y1 );
            }
            x1 += (x1 & -x1);
        }
        z += (z & -z);
    }

}

long long calculate_sum(long long  x,long long y,long long z) {
    long long y1,x1,sum=0;
    while (z>0) {
        x1=x;
        while(x1>0) {
            y1=y;
            while(y1>0) {
                sum += matrix[x1][y1][z];
                y1-= (y1 & -y1);   
            }
            x1 -= (x1 & -x1);
        }
        z -= (z & -z);

    }
    return sum;
}

void process(long long n,long long m) {

    long long x,y,z,x0,y0,z0;
    long long value1,value2,val;
    char command[10];

    memset(matrix,0,sizeof(matrix));

    while(m--) {
        scanf("%s",command);

        if(!strcmp(command,"QUERY")) {
            scanf("%lld %lld %lld %lld %lld %lld",&x0,&y0,&z0,&x,&y,&z);

            value1 = calculate_sum(x,y,z)- calculate_sum(x0-1,y,z) 
                    - calculate_sum(x,y0-1,z) + calculate_sum(x0-1,y0-1,z);

            value2 = calculate_sum(x,y,z0-1) - calculate_sum(x0-1,y,z0-1)
                    - calculate_sum(x,y0-1,z0-1)  + calculate_sum(x0-1,y0-1,z0-1);

            printf("%lld\n",value1 - value2);
            //PrintMatrix(n);

        }

        if(!strcmp(command,"UPDATE")) {

            scanf("%lld %lld %lld %lld",&x,&y,&z,&val);
            x0 = x;
            y0 = y;
            z0 = z ;

            value1 = calculate_sum(x,y,z)- calculate_sum(x0-1,y,z) 
                    - calculate_sum(x,y0-1,z) + calculate_sum(x0-1,y0-1,z);
            value2 = calculate_sum(x,y,z0-1) - calculate_sum(x0-1,y,z0-1)
                    - calculate_sum(x,y0-1,z0-1)  + calculate_sum(x0-1,y0-1,z0-1);

            update(n,x,y,z,val -(value1 - value2 ));

        }

    }
}
int main() {
    long long cases; scanf("%lld",&cases);
    while(cases--) {

        long long n,m; scanf("%lld %lld",&n,&m);
        process(n,m);
    }
    return 0;
}
