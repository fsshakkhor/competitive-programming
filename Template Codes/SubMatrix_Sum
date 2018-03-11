#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1050;
LL n,m,q;
LL bit[1100][1100];
LL ara[1100][1100];
void update(LL x,LL y,LL val)
{
    while(x <= N)
    {
        LL y1 = y;
        while(y1 <= N){
            bit[x][y1] += val;
            y1+=(y1&-y1);
        }
        x+=(x&-x);
    }
}
LL query(LL x,LL y)
{
    LL ret = 0;
    while(x > 0)
    {
        LL y1 = y;
        while(y1 > 0)
        {
            ret += (LL)bit[x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while(t--)
    {
        memset(bit,0,sizeof(bit));
        memset(ara,0,sizeof(ara));
        int q;
        cin >> q;
        while(1)
        {
            string s;
            cin >> s;
            if(s[0] == 'E')break;
            if(s[1] == 'E'){
                LL x,y,num;
                cin >> x >> y >> num;
                x++;y++;
                update(x,y,num - ara[x][y]);
                ara[x][y] = num;
            }else{
                LL x1,y1,x2,y2;
                cin >> x1>> y1 >> x2 >> y2;
                x1++;y1++;x2++;y2++;
                LL answer = query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1);
                cout << answer << "\n";
            }
        }
        cout << "\n";
    }


}
