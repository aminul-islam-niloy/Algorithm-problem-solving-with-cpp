#include<bits/stdc++.h>
using namespace std;

//Matrix chain multiplication (MCM) using DP Memoization technique
const int N = 100, MOD = 1000000007;
int a[N];
int dp[N][N];

int mcm(int i, int j)
{
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = MOD;
    for(int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j],mcm(i, k) + mcm(k + 1, j) + a[i - 1] * a[k] * a[j]);        
    }

    return dp[i][j];
}

int main()
{
    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<mcm(1,n-1)<<endl;
    return 0;
}