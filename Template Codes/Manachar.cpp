#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             2e16
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>


#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);

const int N = 100005;

LL P[2 * N + 5];
LL R[N + 5];

string convertToNewString(const string &s) {
    string newString = "@";

    for (LL i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

LL k;
string longestPalindromeSubstring(const string &s) {
    string Q = convertToNewString(s);
    for(LL i = 0 ;i < Q.size();i++)P[i] = 0;
    LL c = 0, r = 0;

    for (LL i = 1; i < Q.size() - 1; i++) {

        LL iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }


        if (i + P[i] > r) {
            c = i;
            r = i + P[i];
        }
    }


//    cout << Q << endl;
    LL len = s.size();

    for(LL i = 1;i <= len;i++)R[i] = len + 1;

    for(LL i = 1;i <= len;i++){
        LL palen = P[2 * i];
        if(palen < k)continue;
        LL dif = palen - k;
        palen = palen - (dif/2) * 2;

        LL Left = i - palen/2;
        LL Right = i + palen/2;
        R[Left] = min(R[Left],Right);
//        cout << Left << " " << Right << endl;
    }
//    cout << endl;
    for(LL i = 1;i < len;i++){
        LL palen = P[2 * i + 1];
        if(palen < k or palen == 0)continue;
        LL dif = palen - k;
        palen = palen - (dif/2) * 2;

        palen/=2;
        LL Left = i - (palen - 1);
        LL Right = i + palen;
        R[Left] = min(R[Left],Right);
//        cout << Left << " " << Right << endl;
    }
    for(LL i = len - 1;i >= 1;i--){
        R[i] = min(R[i],R[i+1]);
    }
    LL total = (len * (len + 1))/2;
    LL ans = 0;
    FOR(i,1,len)
    {
        ans = ans + (len - R[i] + 1);
    }
    cout << total - ans << "\n";

}

int main()
{
    FastRead
    LL t;
    cin >> t;
    while(t--){
        cin >> k;
        string s;
        cin >> s;
        longestPalindromeSubstring(s);

    }
    return 0;
}
