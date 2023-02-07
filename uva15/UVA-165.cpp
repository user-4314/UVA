#include <iostream>
#include <cstdio>
#define INF 200000000
using namespace std;

int h,k;
int x[10],ans[10],y[1024],maxs,curmax;

void dfs(int i){
    int *backy,backcur;
    int next,postage,num,tmp;
    if(i>=k){
        if(curmax>maxs){
            maxs = curmax;
            for(tmp = 0;tmp<k;tmp++){
                ans[tmp] = x[tmp];
            }
        }
        return;
    }
    backy = (int*)malloc(1024*sizeof(int));
    for(tmp = 0;tmp <1024;tmp++){
        backy[tmp] = y[tmp];
    }
    backcur = curmax;
    for(next = x[i-1]+1;next <= curmax+1;next++){
        x[i]=next;
        for(postage =0;postage < x[i-1]*h;postage++){
            if(y[postage]>h)
                continue;
            for(num = 1;num<=h-y[postage];num++){
                if(y[postage]+num < y[postage + num * next] && (postage + num * next < 1024))
                   y[postage + num * next] = y[postage] + num;
            }
        }
        while(y[curmax+1]<INF)
            curmax++;
        dfs(i+1);
        curmax = backcur;
        for(tmp = 0;tmp<1024;tmp++)
            y[tmp] = backy[tmp];
    }
    free(backy);
}

int main()
{
    int i;
    while(scanf("%d%d",&h,&k) && h!=0){
        x[0]=1;
        curmax = h;
        for(i = 0;i<=curmax;i++)
            y[i] = i;
        while(i<1024)
            y[i++] = INF;
        maxs = 0;
        dfs(1);
        for(int i=0;i<k;i++)
            printf("%3d",ans[i]);
        printf(" ->%3d\n",maxs);
    }
    return 0;
}
