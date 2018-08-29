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


#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);


struct suffix
{
    int index;
    int Rank[2];
};


int cmp(struct suffix a, struct suffix b)
{
    return (a.Rank[0] == b.Rank[0])? (a.Rank[1] < b.Rank[1] ?1: 0):
               (a.Rank[0] < b.Rank[0] ?1: 0);
}

int *buildSuffixArray(char *txt, int n)
{

    struct suffix suffixes[n];


    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].Rank[0] = txt[i] - 'a';
        suffixes[i].Rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
    }

    sort(suffixes, suffixes+n, cmp);

    int ind[n];
    for (int k = 4; k < 2*n; k = k*2)
    {

        int Rank = 0;
        int prev_rank = suffixes[0].Rank[0];
        suffixes[0].Rank[0] = Rank;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++)
        {
            if (suffixes[i].Rank[0] == prev_rank &&
                    suffixes[i].Rank[1] == suffixes[i-1].Rank[1])
            {
                prev_rank = suffixes[i].Rank[0];
                suffixes[i].Rank[0] = Rank;
            }
            else
            {
                prev_rank = suffixes[i].Rank[0];
                suffixes[i].Rank[0] = ++Rank;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].Rank[1] = (nextindex < n)?
                                  suffixes[ind[nextindex]].Rank[0]: -1;
        }

        sort(suffixes, suffixes+n, cmp);
    }

    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;


    return  suffixArr;
}

const int N = 100005;
char str[N];
int done[N],length[N];
void PRINT(int x,int len)
{
   FOR(i,x,len-1)cout << str[i];
   cout << endl;
}
int main()
{
   scanf("%s",str);
   int k;
   scanf("%d",&k);
   int n = strlen(str);
   int *ara = buildSuffixArray(str,n);
   REP(i,n)length[i] = n - ara[i];
//   REP(i,n)PRINT(ara[i],n);
   for(int i = 0;i < n;i++){
      int match_till = n - 1;
      for(int j = ara[i] + done[i];j < n;j++){
         int row = i;
         while(row <= match_till and (i == row or done[i] - 1 == done[row]) ){
            int p = done[row];
//            cout << row << " " << p << " " << str[ara[row] + p] << " " << str[j] << endl;
            if(str[ara[row]+p] == str[j]){
               k = k - 1;
               done[row]++;
               if(k == 0){
//                  cout << ara[row] << " " << ara[row] + done[row] << endl;
                  PRINT(ara[row],ara[row] + done[row]);
                  return 0;
               }

            }else{
               match_till = min(match_till,row);
               break;
            }
            row++;
         }
      }
   }
   cout << "No such line.\n";

}
