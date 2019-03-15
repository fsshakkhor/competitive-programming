#include <bits/stdc++.h>
#define EPS 1e-7
using namespace std;

typedef long long LL;
//this algorithm is O(k log^3 n)

LL ModularMultiplication(LL a, LL b, LL m)
{
	LL ret=0, c=a;
	while(b)
	{
		if(b&1) ret=(ret+c)%m;
		b>>=1; c=(c+c)%m;
	}
	return ret;
}
LL ModularExponentiation(LL a, LL n, LL m)
{
	LL ret=1, c=a;
	while(n)
	{
		if(n&1) ret=ModularMultiplication(ret, c, m);
		n>>=1; c=ModularMultiplication(c, c, m);
	}
	return ret;
}
bool Witness(LL a, LL n)
{
	LL u=n-1;
  int t=0;
	while(!(u&1)){u>>=1; t++;}
	LL x0=ModularExponentiation(a, u, n), x1;
	for(int i=1;i<=t;i++)
	{
		x1=ModularMultiplication(x0, x0, n);
		if(x1==1 && x0!=1 && x0!=n-1) return true;
		x0=x1;
	}
	if(x0!=1) return true;
	return false;
}
LL Random(LL n)
{
  LL ret=rand(); ret*=32768;
	ret+=rand(); ret*=32768;
	ret+=rand(); ret*=32768;
	ret+=rand();
  return ret%n;
}
bool IsPrimeFast(LL n, int TRIAL)
{
    if(n == 1)return false;
    if(n == 2)return true;
  while(TRIAL--)
  {
    LL a=Random(n-2)+1;
    if(Witness(a, n)) return false;
  }
  return true;
}
int main()
{
    srand(time(NULL));
    int N = 1005;;
    vector<int>v;
    for(int i = 1;i < N;i += 22){
        if(IsPrimeFast(i,1))v.push_back(i);
    }

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int num = *lower_bound(v.begin(),v.end(),n);
        printf("%d\n",num);
    }
    return 0;
}
