#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1505;
vector <int> g[N];
int dp[N][2];

void dfs(int u,int pa){
    dp[u][0]=0,dp[u][1]=1;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==pa)
            continue;

        dfs(v,u);
        dp[u][0]=dp[u][0]+dp[v][1];
        dp[u][1]=dp[u][1]+min(dp[v][0],dp[v][1]);
    }
}

int main()
{   int n,node,m,leaf;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            g[i].clear();

        for(int i=0;i<n;i++){
            scanf("%d:(%d)",&node,&m);
            for(int j=0;j<m;j++){
                scanf("%d",&leaf);
                g[node].push_back(leaf);
                g[leaf].push_back(node);
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
