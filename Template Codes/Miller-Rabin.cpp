#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

typedef pair<ll,ll> PLL;
namespace Factor {
	const int N=2010000;
	ll C,fac[10010],n,mut,a[1001000];
	int T,cnt,i,l,prime[N],p[N],psize,_cnt;
	ll _e[100],_pr[100];
	vector<ll> d;
	inline ll mul(ll a,ll b,ll p) {
		if (p<=1000000000) return a*b%p;
		else if (p<=1000000000000ll) return (((a*(b>>20)%p)<<20)+(a*(b&((1<<20)-1))))%p;
		else {
			ll d=(ll)floor(a*(long double)b/p+0.5);
			ll ret=(a*b-d*p)%p;
			if (ret<0) ret+=p;
			return ret;
		}
	}
	void prime_table(){
		int i,j,tot,t1;
		for (i=1;i<=psize;i++) p[i]=i;
		for (i=2,tot=0;i<=psize;i++){
			if (p[i]==i) prime[++tot]=i;
			for (j=1;j<=tot && (t1=prime[j]*i)<=psize;j++){
				p[t1]=prime[j];
				if (i%prime[j]==0) break;
			}
		}
	}
	void init(int ps) {
		psize=ps;
		prime_table();
	}
	ll powl(ll a,ll n,ll p) {
		ll ans=1;
		for (;n;n>>=1) {
			if (n&1) ans=mul(ans,a,p);
			a=mul(a,a,p);
		}
		return ans;
	}
	bool witness(ll a,ll n) {
		int t=0;
		ll u=n-1;
		for (;~u&1;u>>=1) t++;
		ll x=powl(a,u,n),_x=0;
		for (;t;t--) {
			_x=mul(x,x,n);
			if (_x==1 && x!=1 && x!=n-1) return 1;
			x=_x;
		}
		return _x!=1;
	}
	bool miller(ll n) {
		if (n<2) return 0;
		if (n<=psize) return p[n]==n;
		if (~n&1) return 0;
		for (int j=0;j<=7;j++) if (witness(rand()%(n-1)+1,n)) return 0;
		return 1;
	}
	ll gcd(ll a,ll b) {
		ll ret=1;
		while (a!=0) {
			if ((~a&1) && (~b&1)) ret<<=1,a>>=1,b>>=1;
			else if (~a&1) a>>=1; else if (~b&1) b>>=1;
			else {
				if (a<b) swap(a,b);
				a-=b;
			}
		}
		return ret*b;
	}
	ll rho(ll n) {
		for (;;) {
			ll X=rand()%n,Y,Z,T=1,*lY=a,*lX=lY;
			int tmp=20;
			C=rand()%10+3;
			X=mul(X,X,n)+C;*(lY++)=X;lX++;
			Y=mul(X,X,n)+C;*(lY++)=Y;
			for(;X!=Y;) {
				ll t=X-Y+n;
				Z=mul(T,t,n);
				if(Z==0) return gcd(T,n);
				tmp--;
				if (tmp==0) {
					tmp=20;
					Z=gcd(Z,n);
					if (Z!=1 && Z!=n) return Z;
				}
				T=Z;
				Y=*(lY++)=mul(Y,Y,n)+C;
				Y=*(lY++)=mul(Y,Y,n)+C;
				X=*(lX++);
			}
		}
	}
	void _factor(ll n) {
		for (int i=0;i<cnt;i++) {
			if (n%fac[i]==0) n/=fac[i],fac[cnt++]=fac[i];}
		if (n<=psize) {
			for (;n!=1;n/=p[n]) fac[cnt++]=p[n];
			return;
		}
		if (miller(n)) fac[cnt++]=n;
		else {
			ll x=rho(n);
			_factor(x);_factor(n/x);
		}
	}
	void dfs(ll x,int dep) {
		if (dep==_cnt) d.pb(x);
		else {
			dfs(x,dep+1);
			for (int i=1;i<=_e[dep];i++) dfs(x*=_pr[dep],dep+1);
		}
	}
	void norm() {
		sort(fac,fac+cnt);
		_cnt=0;
		rep(i,0,cnt) if (i==0||fac[i]!=fac[i-1]) _pr[_cnt]=fac[i],_e[_cnt++]=1;
			else _e[_cnt-1]++;
	}
	vector<ll> getd() {
		d.clear();
		dfs(1,0);
		return d;
	}
	vector<ll> factor(ll n) {
		cnt=0;
		_factor(n);
		norm();
		return getd();
	}
	vector<PLL> factorG(ll n) {
		cnt=0;
		_factor(n);
		norm();
		vector<PLL> d;
		rep(i,0,_cnt) d.pb(mp(_pr[i],_e[i]));
		return d;
	}
	bool is_primitive(ll a,ll p) {
		assert(miller(p));
		vector<PLL> D=factorG(p-1);
		rep(i,0,SZ(D)) if (powl(a,(p-1)/D[i].fi,p)==1) return 0;
		return 1;
	}
}
using namespace std;
int pre[110][110],_;
ll n[10],m[10],s[10],ans;
int ppr[110],ff[110],ee[110],cntt;
map<ll,int> mn,mm,ms;
vector<ll> d;
void gao(ll *a,map<ll,int> &hs) {
	hs.clear();
	a[0]=a[1]*a[2]*a[3];
	rep(i,1,4) {
		vector<PLL> d=Factor::factorG(a[i]);
		for (auto v:d) hs[v.fi]+=v.se;
	}
}
void dfs(ll x,int dep) {
	if (dep==cntt) {
		d.pb(x);
//		printf("ff %lld\n",x);
	} else {
		dfs(x,dep+1);
		for (int i=1;i<=ee[dep];i++) dfs(x*=ppr[dep],dep+1);
	}
}
void dfs2(ll x,int dep,int sign) {
	if (sign==0) return;
	if (dep==cntt) {
		ans+=sign*(m[0]/x);
	} else {
		dfs2(x,dep+1,sign*pre[0][ff[dep]]);
		for (int i=1;i<=ee[dep];i++) dfs2(x*=ppr[dep],dep+1,sign*pre[i][ff[dep]]);
	}
}
void gen(map<ll,int> hs) {
	d.clear();
	cntt=0;
	for (auto p:hs) ppr[cntt]=p.fi,ee[cntt]=p.se,cntt++;
//	printf("gg %d\n",cntt);
	dfs(1,0);
}
#define LL long long
LL nums[] = {2,3,5,7};
char str[20];
LL numbers,ara[20];

int we_got;
LL answer;
void rec(LL pos,LL tight,LL num)
{
    if(we_got)return;
    if(pos == numbers){
        bool IsPrime = Factor::miller(num);
        if(IsPrime == 1){
            we_got = 1;
            answer = num;
        }

        return;
    }
    if(pos < numbers - 1 or num == 0){
        for(LL i = 3;i >= 0;i--){
            if(tight == 1){
                if(nums[i] < ara[pos]){
                    LL newtight = 0;
                    rec(pos + 1,newtight,10 * num + nums[i]);
                }else if(nums[i] == ara[pos]){
                    LL newtight = 1;
                    rec(pos + 1,newtight,10 * num + nums[i]);
                }
            }else{
                rec(pos + 1,0,10 * num + nums[i]);
            }
        }
    }else{
       for(LL i = 3;i >= 0;i = i - 2){
            if(tight == 1){
                if(nums[i] < ara[pos]){
                    LL newtight = 0;
                    rec(pos + 1,newtight,10 * num + nums[i]);
                }else if(nums[i] == ara[pos]){
                    LL newtight = 1;
                    rec(pos + 1,newtight,10 * num + nums[i]);
                }
            }else{
                rec(pos + 1,0,10 * num + nums[i]);
            }
        }
    }
}

int main() {

	Factor::init(2000000);

    LL t,cases = 0;
    cin >> t;
    while(t--){
        we_got = 0;

        cin >> str;
        numbers = strlen(str);
        for(LL i = 0;i < numbers;i++)ara[i] = str[i] - '0';
        for(LL i = 0;i < numbers;i++){
            if(i == 0)rec(i,1,0);
            else rec(i,0,0);
        }

        cout << "Case " << ++cases << ": " << answer << "\n";
    }
}
