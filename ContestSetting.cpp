
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005],b[1005],c[1005];
int dp[1005][1005];
const int mod=998244353;
signed main()
{
    int n,k;
    memset(c,0,sizeof c);
    memset(dp,0,sizeof dp);
         // Discretization!
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    int m=unique(a+1,a+n+1)-a-1;
    for(int i=1;i<=n;i++)
    {
        b[i]=lower_bound(a+1,a+m+1,b[i])-a;
        c[b[i]]++;
    }
    
         //dp initialization
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
 
         for(int i=1;i<=m;i++) //The point is that i refers to the number 1-i (discrete)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=((dp[i-1][j-1]*c[i])%mod+dp[i-1][j])%mod;
        }
    }
    cout << dp[m][k] << endl;
    return 0;
}