 Home
Problem
Status
Contest
User
Group
Forum
Article
Logout
fsshakkhor
Begin: 2018-06-10 00:20 BST
Contest for Zico, Protik, Shakkhor 10/06/2018
End: 2018-07-05 00:20 BST
600:00:00
Ended
Overview
Problem
Status
Rank (600:00:00)
2 Comments
Previous12345…Next
Run ID	Username

Prob
	Result 
	Time
(ms)	Mem
(MB)	Length	Lang 
	Submit Time
14237525	
fsshakkhor
B
Accepted
50	20.5	2496	
C++
1 months ago
           
All Copyright Reserved ©2018 Xu Han
Server Time: 2018-07-20 17:10:26 BST

#14237525 | fsshakkhor's solution for [SPOJ-LPS] [Problem B]
Status
Accepted
Time
50ms
Memory
20480kB
Length
2496
Lang
C++14 (clang 4.0)
Submitted
2018-06-10 03:42:57
Shared

RemoteRunId
21810276
Select Code
#include<bits/stdc++.h>

using namespace std;

#define fRead(x)  freopen(x,"r",stdin)
#define fWrite(x) freopen (x,"w",stdout)

#define LL long long
#define ULL unsigned long long
#define ff first
#define ss second
#define pb push_back
#define INF 2e16
#define PI acos(-1.0)
#define mk make_pair

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,b) for(int i=0;i<b;i++)
#define MEM(a,x) memset(a,x,sizeof(a))
#define ABS(x) ((x)<0?-(x):(x))

#define scanI(a) scanf("%d",&a)
#define scanI2(a,b) scanI(a) , scanI(b)
#define scanI3(a,b,c) scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a) scanf("%I64d",&a)
#define scanL2(a,b) scanL(a) , scanL(b)
#define scanL3(a,b,c) scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

#define SORT(v) sort(v.begin(),v.end())
#define REV(v) reverse(v.begin(),v.end())

#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);

const int N = 200005;
const int M = 44444;
const ULL hs = 3797;

ULL F[N], L[N], R[N];
char in[N];
int n;

ULL seg(int x, int y) {
    return (L[y] - L[x-1]) * F[n - y];
}
ULL seg2(int x, int y) {
    return (R[x] - R[y + 1]) * F[x - 1];
}
int main()
{
    scanf("%d",&n);
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs;
    scanf("%s", in + 1);
    n = strlen(in + 1);

    FOR(i, 1, n) L[i] = L[i - 1] + in[i] * F[i - 1];
    ROF(i, n, 1) R[i] = R[i + 1] + in[i] * F[n - i];

    int mx = 0;
    for(int i = 1; i <= n;i++){
        int lo = 1, hi = min(i,n - i + 1) , mid,ans = 0;

        while(lo <= hi){
            mid = (lo + hi)/2;
            if(seg(i-mid+1,i+mid-1) == seg2(i-mid+1,i+mid-1)){
                ans = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        mx = max(mx,ans * 2 - 1);
    }
    for(int i = 1; i <= n;i++){
        int lo = 0, hi = min(i,n - i) , mid,ans = 0;

        while(lo <= hi){
            mid = (lo + hi)/2;
            if(seg(i-mid+1,i+mid) == seg2(i-mid+1,i+mid)){
                ans = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        mx = max(mx,ans * 2);
    }
    cout << mx << endl;
    return 0;
}

Comment in Markdown
Preview:
