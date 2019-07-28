#include<bits/stdc++.h>
using namespace std;
const int N = 1;
double mat[N][N + 1];
void RowSwap(int i, int j)
{
    for (int k=0; k<=N; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}
int ForwardElemination()
{
    for (int k=0; k<N; k++)
    {
        int i_max = k;
        int v_max = mat[i_max][k];

        for (int i = k+1; i < N; i++)if (abs(mat[i][k]) > v_max)v_max = mat[i][k], i_max = i;

        if (!mat[k][i_max]) return k;

        if (i_max != k)RowSwap(k, i_max);

        for (int i=k+1; i<N; i++)
        {
            double f = mat[i][k]/mat[k][k];
            for (int j=k+1; j<=N; j++)mat[i][j] -= mat[k][j]*f;
            mat[i][k] = 0;
        }
    }
    return -1;
}

void BackSubstitution()
{
    double x[N];
    for (int i = N-1; i >= 0; i--)
    {
        x[i] = mat[i][N];

        for (int j=i+1; j<N; j++)
        {
            x[i] -= mat[i][j]*x[j];
        }
        x[i] = x[i]/mat[i][i];
    }
    printf("\nSolution for the system:\n");
    for (int i=0; i<N; i++)
    cout << x[i] << endl;
}
int main()
{
    mat[0][0] = 2;
    mat[0][1] = 1;
    ForwardElemination();//Call this First
    BackSubstitution();//Then Back Sub
}
