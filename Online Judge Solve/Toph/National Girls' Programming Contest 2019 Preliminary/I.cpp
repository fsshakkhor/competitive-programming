#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             1e9
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

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);
const string EMPTY = "";
map<string,int>mp;
string X[] = { EMPTY, "One ", "Two ", "Three ", "Four ", "Five ",
				"Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ",
				"Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
				"Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };

string Y[] = { EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ",
				"Sixty ", "Seventy ", "Eighty ", "Ninety " };


void TOLOWER(string &s)
{
    while(s.size() > 0 and s.back() == ' ')s.pop_back();
    for(int i = 0;i < s.size();i++)s[i] = tolower(s[i]);
}
void preprocess()
{
    for(int i = 0;i <= 19;i++)TOLOWER(X[i]);
    for(int i = 0;i <= 9;i++)TOLOWER(Y[i]);

    for(int i = 0;i <= 9;i++)mp[Y[i]] = i * 10;
    for(int i = 0;i <= 19;i++)mp[X[i]] = i;

}
void make(string str,vector<string>&vec)
{
    string temp;
    for(int i = 0;i < str.size();i++){
        if(str[i] == ' '){
            vec.push_back(temp);
            temp.clear();
        }else{
            temp += str[i];
        }
    }
    vec.push_back(temp);
}

int main()
{
    preprocess();

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string str;
        getline(cin,str);
        vector<string>vec;
        make(str,vec);

        int ans = 0;
        int done = -1;
        for(int i = 0;i < vec.size();i++){
            if(vec[i] == "thousand"){
                int v = mp[vec[i - 1]];
                ans = ans + v * 1000;
                done = i;
            }
            if(vec[i] == "hundred"){
                int v = mp[vec[i - 1]];
                ans = ans + v * 100;
                done = i;
            }
        }
        for(int i = done + 1;i < vec.size();i++){
            ans = ans + mp[vec[i]];
        }
        vector<int>bin;
        while(ans > 0){
            bin.push_back(ans % 2);
            ans/=2;
        }
        vector<int>rev = bin;
        REV(rev);
        if(bin == rev)cout << "YES\n";
        else cout << "NO\n";

    }

}
