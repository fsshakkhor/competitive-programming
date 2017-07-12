int N = 15;

int mu[N+1];
memset(mu,0,sizeof(mu));
mu[1] = 1;

for(int i = 1;i<=N;++i)
    for(int j = 2*i;j<=N;j += i)
        mu[j] -= mu[i];

for(int i = 1;i<=N;++i)
    printf("%d : %d\n",i,mu[i]);
