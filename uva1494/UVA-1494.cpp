#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n,m;
int x[N],y[N],p[N];

struct edge{
    int u,v;
    double cost;
    bool operator<(const edge &a)const{
        return cost<a.cost;
    }
}e[N*N];


vector <edge> g[N];
int head[N];

int f(int x){
    return x == head[x] ? x : head[x]=f(head[x]);
}

bool unit(int a,int b){
    int x = f(a), y=f(b);
    if(x==y)
        return false;
    head[x] = y;
    return true;
}

double dis(int a,int b){
    double x2 = (x[a]-x[b])*(x[a]-x[b]);
    double y2 = (y[a]-y[b])*(y[a]-y[b]);
    return sqrt(x2+y2);
}

double kruskal(){
    m=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            e[m++]=(edge){i,j,dis(i,j)};
    }

    sort(e,e+m);
    for(int i=0;i<n;i++){
        head[i]=i;
        g[i].clear();
    }

    double ans = 0;
    int edgecount = 0;

    for(int i=0;i<m;i++){
        int u=e[i].u, v=e[i].v;
        double c=e[i].cost;
        if(unit(u,v)){
            g[u].push_back((edge){u,v,c});
            g[v].push_back((edge){v,u,c});
            ans=ans+c;
            if(++edgecount == n-1)
                break;
        }
    }
    return ans;
}

double maxc[N][N];
vector <int> visit;

void dfs(int u,int v,double w){
    for(int x=0;x<visit.size();x++)
        maxc[x][v]=maxc[v][x]=max(maxc[x][u],w);
    visit.push_back(v);

    for(int i=0;i < g[v].size();i++){
        int nextv = g[v][i].v;
        if(nextv==u)
            continue;
        dfs(v,nextv,g[v][i].cost);
    }
}

void findpathmax(){
    memset(maxc,0,sizeof(maxc));
    visit.clear();
    dfs(-1,0,0.0);
}

void solve(){
    double minc = kruskal();
    findpathmax();
    double ans=-1;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            ans = max(ans,(p[i]+p[j])/(minc-maxc[i][j]));
    }
    printf("%.2lf\n",ans);
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&x[i],&y[i],&p[i]);
        solve();

    }
    return 0;
}
