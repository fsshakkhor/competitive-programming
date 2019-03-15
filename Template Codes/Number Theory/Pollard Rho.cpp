#include <bits/stdc++.h>
#define LL long long

using namespace std;
int main (int argc, char *argv[])
{
    srand(time(NULL));
    LL number = 1000000009LL * 100000007, loop = 1, count;
    LL x_fixed = 2, x = 2, size = 2, factor;
    LL iterations = 0;
    do {
//        printf("----   loop %4i   ----\n", loop);
        count = size;
        do {
            iterations++;
            x = (x * x + 1) % number;
            factor = __gcd(abs(x - x_fixed), number);
//            printf("count = %4i  x = %6i  factor = %i\n", size - count + 1, x, factor);
        } while (--count && (factor == 1));
        size *= 2;
        x_fixed = x;
        loop = loop + 1;
    } while (factor == 1);
    printf("%d\n",iterations);
    printf("factor is %i\n", factor);

}
