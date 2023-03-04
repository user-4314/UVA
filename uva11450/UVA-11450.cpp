#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool price[205][25];
int main()
{   int cas,m,c,k[25],garment[25][25];
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&m,&c);
        for(int i=0;i<c;i++){
            scanf("%d",&k[i]);
            for(int j=0;j<k[i];j++){
                scanf("%d",&garment[i][j]);
            }
        }
        memset(price,false,sizeof(price));

        for(int i=0;i<k[0];i++){
            if(m-garment[0][i] < 0)
                continue;
            price[m-garment[0][i]][0] = true;
        }

        for(int i=1;i<c;i++){
            for(int j=0;j<m;j++){
                if(price[j][i-1]){
                    for(int n=0;n<k[i];n++){
                        if( j-garment[i][n] < 0 )
                            continue;

                        price[j-garment[i][n]][i] = true;
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            if(price[i][c-1]){
                printf("%d\n",m-i);
                break;
            }
            else if(i==m-1)
                printf("no solution\n");
        }
    }
    return 0;
}
