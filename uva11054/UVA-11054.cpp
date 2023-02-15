#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{   int n;
    long long a[100000];
    while(scanf("%d",&n) && n!=0){
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        long long x=0,ans=0;
        for(int i=0;i<n;i++){
            ans=ans+abs(x);
            x=x-a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
