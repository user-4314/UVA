#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1005;
int n,s,k,p[N];
vector <int> g[N],node[N];
bool c[N];

void dfs1(int u,int f,int dis){
    p[u]=f;
    int leaf = g[u].size();
    if(leaf == 1 && dis >k)
        node[dis].push_back(u);
    for(int i=0;i<leaf;i++){
        int v = g[u][i];
        if(v!=f)
            dfs1(v,u,dis+1);
    }
}

void dfs2(int u,int f,int dis){
    c[u] = true;
    int nd = g[u].size();
    for(int i=0;i<nd;i++){
        int v=g[u][i];
        if(v!=f && dis<k)
            dfs2(v,u,dis+1);
    }
}

int sol(){
    int ans = 0;
    memset(c,false,sizeof(c));
    for(int dis=n-1;dis>k;dis--){
        for(int i=0;i<node[dis].size();i++){
            int u = node[dis][i];
            if(c[u])
                continue;
            int v=u;
            for(int j=0;j<k;j++)
                v=p[v];
            dfs2(v,-1,0);
            ans++;
        }
    }
    return ans;
}

int main()
{   int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&n,&s,&k);
        for(int i=1;i<=n;i++){
            g[i].clear();
            node[i].clear();
        }
        for(int i=0;i<n-1;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs1(s,-1,0);
        printf("%d\n",sol());
    }
    return 0;
}
