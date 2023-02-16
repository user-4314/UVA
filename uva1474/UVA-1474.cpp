#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 4000
#define INF 0x3f3f3f3f3f3f3f3f
int n,m;
long long dp[2][N];
int path[N][N];
int ans[N];

struct node{
    int p,id;
    bool operator < (const node& a)const{
        return p < a.p;
    }
}team[N],shelter[N];

int main()
{   while(~scanf("%d",&n)){
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            scanf("%d",&team[i].p);
            team[i].id=i;
        }
        sort(team+1,team+n+1);
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&shelter[i].p);
            shelter[i].id=i;
        }
        sort(shelter+1,shelter+m+1);

        for(int i=1;i<=n;i++)
            dp[0][i]=INF;
        for(int i=1;i<=m;i++){
            dp[i&1][i-1]=INF;
            for(int j=i;j<=n;j++){
                if(dp[(i+1)&1][j-1]<dp[i&1][j-1]){
                    dp[i&1][j]=dp[(i+1)&1][j-1]+abs(team[j].p-shelter[i].p);
                    path[i][j]=1;
                }
                else{
                    dp[i&1][j]=dp[i&1][j-1]+abs(team[j].p-shelter[i].p);
                    path[i][j]=0;
                }
            }
        }
        int back_track = m;
        for(int i=n;i>0;i--){
            ans[team[i].id]=shelter[back_track].id;
            back_track-=path[back_track][i];
        }
        printf("%lld\n",dp[m&1][n]);
        for(int i=1;i<=n;i++){
            if(i!=1)
                printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }

    return 0;
}
