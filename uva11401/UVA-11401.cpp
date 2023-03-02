#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1000005;
long long ans[N];
int main()
{   int n;

    ans[3]=0;
    for(long long i=4;i<N;i++)
        ans[i]=ans[i-1]+((i-1)*(i-2)/2-(i-1)/2)/2;

    while(scanf("%d",&n) && n>=3)
        printf("%lld\n",ans[n]);

    return 0;
}
