#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=510;
const int maxm=2e3+7;
typedef pair<int,int> P;
struct Node
{
    int to;
    int val;
    int next;
}edge[maxm<<1];
int cnt;
int head[maxn];
int dis_from_start[maxn];
int dis_from_end[maxn];
int pre_from_start[maxn];
int pre_from_end[maxn];

void init()
{
    memset(head,-1,sizeof(head));
    memset(pre_from_start,-1,sizeof(pre_from_start));
    memset(pre_from_end,-1,sizeof(pre_from_end));
    memset(dis_from_start,inf,sizeof(dis_from_start));
    memset(dis_from_end,inf,sizeof(dis_from_end));
    cnt=0;
    return;
}

void add(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    return;
}

void dijkstra(int x,int *dis,int *pre)
{
    priority_queue < P, vector <P>, greater<P> > que;
    dis[x]=0;
    que.push(make_pair(0,x));
    while(!que.empty())
    {
        P now=que.top();
        que.pop();
        int node=now.second;
        int now_dis=now.first;
        if(dis[node]<now_dis) continue;
        for(int i=head[node];~i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[node]+edge[i].val)
            {
                dis[v]=dis[node]+edge[i].val;
                pre[v]=node;
                que.push(make_pair(dis[v],v));
            }
        }
    }
    return;
}

int main()
{   int n,s,e;
    int cas=0;
    while(~scanf("%d%d%d",&n,&s,&e))
    {
        init();
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        dijkstra(s,dis_from_start,pre_from_start);
        dijkstra(e,dis_from_end,pre_from_end);
        int ans=dis_from_start[e];
        int source=-1,sink=-1;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            int res=dis_from_start[u]+dis_from_end[v]+w;
            if(ans>res)
            {
                ans=res;
                source=u;
                sink=v;
            }
            res=dis_from_start[v]+dis_from_end[u]+w;
            if(ans>res)
            {
                source=v;
                sink=u;
                ans=res;
            }
        }
        if(cas) cout<<endl;
        else cas++;
        if(source!=-1)
        {
        	int ans_source=source;
            vector<int> ans;
            while(source!=-1)
            {
                ans.push_back(source);
                source=pre_from_start[source];
            }
            int len=ans.size();
            for(int i=len-1;i>=0;i--)
            {
                cout<<ans[i]<<' ';
            }
            ans.clear();
            while(sink!=-1)
            {
                ans.push_back(sink);
                sink=pre_from_end[sink];
            }
            len=ans.size();
            for(int i=0;i<len-1;i++)
            {
                cout<<ans[i]<<' ';
            }
            cout<<ans[len-1]<<endl;
            cout<<ans_source<<endl;
        }
        else
        {
            vector<int> ans;
            while(e!=-1)
            {
                ans.push_back(e);
                e=pre_from_start[e];
            }
            int len=ans.size();
            for(int i=len-1;i>=1;i--)
            {
                cout<<ans[i]<<' ';
            }
            cout<<ans[0]<<endl;
            cout<<"Ticket Not Used"<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
