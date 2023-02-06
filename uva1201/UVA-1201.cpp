#include <cstring>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

const int N = 500;
bool left[N],right[N];
int pairwith[N],time[N],m;
vector<int>  g[N];

int dis(int x1,int x2,int y1,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

bool match(int u){
    left[u]=true;

    for(int i=0;i<g[u].size();i++){
       int j=g[u][i];
       if(!right[j]){
            right[j]=true;
            if( !pairwith[j] || match(pairwith[j]) ){
                pairwith[j]=u;
                return true;
            }
       }
    }
    return false;
}

int KM(){
    int maxpair=0;
    memset(pairwith,0,sizeof(pairwith));
    for(int i=1;i<m;i++){
        memset(left,false,sizeof(left));
        memset(right,false,sizeof(right));
        if(match(i))
            maxpair++;
    }
    return maxpair;
}

int main()
{   int cas,h,mm,x1[N],x2[N],y1[N],y2[N];

    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            char c;
            g[i].clear();
            scanf("%d%c%d%d%d%d%d",&h,&c,&mm,&x1[i],&y1[i],&x2[i],&y2[i]);
            time[i]=h*60+mm;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i!=j){
                    int last = time[i]+dis(x1[i],x2[i],y1[i],y2[i])+dis(x2[i],x1[j],y2[i],y1[j]);
                    if(last < time[j])
                        g[i].push_back(j);
                }
            }
        }

        printf("%d\n",m-KM());
    }

    return 0;
}
