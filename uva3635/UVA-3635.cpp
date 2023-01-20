#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
int main()
{   int cas,n,f,r;
    scanf("%d",&cas);
    while(cas--){
        double ma=0,area[10000];
        scanf("%d%d",&n,&f);
        f=f+1;
        for(int i=0;i<n;i++){
            scanf("%d",&r);
            area[i]=r*r*pi;
            ma=max(ma,area[i]);
        }

        double l=0,r=ma;
        while(r-l>0.0000001){
            double mid=(l+r)/2;
            int piece=0;
            for(int i=0;i<n;i++){
                piece=piece+area[i]/mid;
            }
            if(piece>=f){
                l=mid;
            }
            else{
                r=mid;
            }

        }
        printf("%.4lf\n",l);
    }

    return 0;
}
