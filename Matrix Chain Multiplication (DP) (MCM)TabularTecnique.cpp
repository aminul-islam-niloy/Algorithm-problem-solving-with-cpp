#include<bits/stdc++.h>
using namespace std;
//Matrix chain multiplication (MCM) using Tabular technique
const int N = 100, MOD = 1000000007;
int a[N];
int dp[N][N];
int main()
{
    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        dp[i][i] = 0;
    }

    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j = i+l-1;
            dp[i][j] = MOD;
            for(int k=i;k<j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
            }
        }
    }
    cout<<dp[1][n-1]<<endl;
    return 0;
}