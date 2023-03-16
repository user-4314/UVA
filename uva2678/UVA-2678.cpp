#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100005;
int a[N],b[N];
int main()
{   int n,s;
    while(scanf("%d%d",&n,&s) && n){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        b[0] = 0;
        for(int i=1;i<=n;i++)
            b[i]=b[i-1]+a[i];

        int ans = n+1;
        int i=1;
        for(int j=1;j<=n;j++){
            if(b[i-1]>b[j]-s)
                continue;
            while(b[i]<=b[j]-s)
                i++;
            ans = min(ans,j-i+1);
        }
        printf("%d\n",ans == n+1 ? 0 :ans);

    }
    return 0;
}
