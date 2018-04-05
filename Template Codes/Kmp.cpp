#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             5e13
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

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

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

int F[1000005];
string str,s;
vector<int>v;
void match()
{
   int cnt = 0;
   int j = 0;
   for(int i = 0;i < str.size();i++){
      while(j > 0 and str[i] != s[j]){
         j = F[j-1];
      }
      if(str[i] == s[j])j++;
      if(j == s.size())j = F[j-1],v.push_back(i - s.size() + 2);
   }
}
void prefix_function()
{
   F[0] = 0;
   for(int i = 1;i<s.size();i++){
      int j = F[i-1];
      while(j > 0 and s[j] != s[i]){
         j = F[j-1];
      }
      if(s[i] == s[j])j++;
      F[i] = j;
   }
}
int main()
{
   FastRead
   int t;
   cin >> t;
   while(t--)
   {
      v.clear();
      cin >> str >> s;
      prefix_function();
      match();
      if(v.empty())cout << "Not Found\n";
      else{
         cout << v.size() << "\n";
         for(int i = 0;i<v.size();i++){
            if(i)cout << " ";
            cout << v[i];
         }
         cout << "\n";
      }
      if(t)cout << "\n";
   }

}

