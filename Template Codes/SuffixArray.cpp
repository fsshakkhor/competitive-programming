#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


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

char str[40005];
int main()
{
    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%s",str);
        int len = strlen(str);
        for(int i = 0;i < len;i++)str[i + len] = str[i];
        str[2 * len] = 'z';
        int *ara = buildSuffixArray(str,2 * len + 1);
//        for(int i = 0;i < 2 * len;i++)cout << ara[i] << " ";
//        cout << endl;

        int ans = 0;
        for(int i = 0;i <= 2 * len;i++){
            if(ara[i] < len){
                ans = ara[i];
                break;
            }
        }
        printf("%d\n",ans + 1);
    }
    return 0;
}
