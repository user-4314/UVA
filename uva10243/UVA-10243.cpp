#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define N 1000
int dp[N][2];
vector <int> g[N];

void dfs(int u,int pa){
    dp[u][0]=dp[u][1]=0;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==pa)
            continue;

        dfs(v,u);
        dp[u][0]=dp[u][0]+dp[v][1];
        dp[u][1]=dp[u][1]+min(dp[v][0],dp[v][1]);
    }
    dp[u][1]++;
}

int main()
{   int n,k,v;

    while(scanf("%d",&n )&& n!=0){
        for(int i=0;i<=n;i++)
            g[i].clear();

        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&v);
                g[i].push_back(v);
            }
        }

        if(n==1){
            printf("1\n");
            continue;
        }
        dfs(1,-1);
        printf("%d\n",min(dp[1][0],dp[1][1]));
    }

    return 0;
}
