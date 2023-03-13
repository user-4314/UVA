#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int k,m;
int dp[15][105][105];
const int INF = 0x3f3f3f3f;

int dfs(int mail,int start,int ed){
    if(dp[mail][start][ed] != -1) return dp[mail][start][ed];
    if(start>ed) return 0;

    int ans = INF;
    for(int i=start;i<=ed;i++)
        ans = min(ans,i+max( dfs(mail-1,start,i-1) , dfs(mail,i+1,ed) ) );
    return dp[mail][start][ed] = ans;
}

int main()
{   int n;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=100;i++){
        for(int j=i;j<=100;j++){
            dp[1][i][j]=(i+j)*(j-i+1)/2;
        }
    }
    while(n--){
        scanf("%d%d",&k,&m);
        printf("%d\n",dfs(k,1,m));

    }
    return 0;
}
