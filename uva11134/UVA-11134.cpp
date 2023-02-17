#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 5005
struct Rook{
    int s,e,id,ans;
    bool operator <(const Rook &other)const{
        return e < other.e;
    }
}X[N],Y[N];

bool sol(Rook R[],int n){
    sort(R,R+n);
    int use[N];
    memset(use,0,sizeof(use));
    for(int i=0;i<n;i++){
        for(int j=R[i].s;j<=R[i].e;j++){
            if(!use[j]){
                R[i].ans=j;
                use[j]=1;
                break;
            }
        }
        if(R[i].ans == 0)
            return false;
    }
    return true;
}

int main()
{   int n;
    while(scanf("%d",&n) && n!=0){
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&X[i].s,&Y[i].s,&X[i].e,&Y[i].e);
            X[i].id=Y[i].id=i;
            X[i].ans=Y[i].ans=0;
        }
        if(!sol(X,n) || !sol(Y,n))
            printf("IMPOSSIBLE\n");
        else{
            int x[N],y[N];
            for(int i=0;i<n;i++){
                x[X[i].id]=X[i].ans;
                y[Y[i].id]=Y[i].ans;
            }
            for(int i=0;i<n;i++)
                printf("%d %d\n",x[i],y[i]);
        }
    }
    return 0;
}
