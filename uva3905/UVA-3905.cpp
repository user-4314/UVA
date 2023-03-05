#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;

struct Event {
    double x;
    int type;
    bool operator < (const Event& a) const {
        return x < a.x || (x == a.x && type > a.type);
    }
} event[N*2];

void update(int x,int a,int w,double &l,double &r){
    if(a==0){
        if(x<=0 || x>=w)
            r = l-1;
    }
    else if(a>0){
        l = max(l,(double)(0-x)/a);
        r = min(r,(double)(w-x)/a);
    }
    else{
        l = max(l, (double)(w-x)/a);
        r = min(r, (double)(0-x)/a);
    }
}

int main()
{   int cas;
    scanf("%d",&cas);
    while(cas--){
        int w,h,n,e=0;
        scanf("%d%d%d",&w,&h,&n);
        for(int i=0;i<n;i++){
            int x,y,a,b;
            scanf("%d%d%d%d",&x,&y,&a,&b);
            double l = 0,r = 1e9;
            update(x,a,w,l,r);
            update(y,b,h,l,r);
            if(r>l){
                event[e++]=(Event){l, 0};
                event[e++]=(Event){r,1};
            }
        }
        sort(event,event+e);
        int cnt =0,ans=0;
        for(int i=0;i<e;i++){
            if(event[i].type==0)
                ans = max(ans,++cnt);
            else
                cnt--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
